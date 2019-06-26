#include "ActorDrawer.h"
#include "Actor.h"
#include "IShape.h"
#include "Program.h"
#include "Shader.h"
#include "GLEW/glew.h"
#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/ext/matrix_clip_space.hpp"
#include "OrthographicCamera.h"
#include "Character.h"

#include <fstream>

namespace
{
    constexpr const char VertexShaderPath[] = "./Shader/VertexShader.glsl";
    constexpr const char FragmentShaderPath[] = "./Shader/FragmentShader.glsl";

    constexpr int PositionAttributeIndex = 0;
    constexpr int ColorAttributeIndex = 1;
    constexpr const char MatrixVariableName[] = "TransformationMatrix";

    GLuint GenerateVao()
    {
        GLuint newVertexArray = 0;
        glGenVertexArrays(1, &newVertexArray);
        glBindVertexArray(newVertexArray);

        return newVertexArray;
    }

    GLuint GenerateVbo(const std::vector<float>& bufferData)
    {
        GLuint newBuffer = 0;

        glGenBuffers(1, &newBuffer);
        glBindBuffer(GL_ARRAY_BUFFER, newBuffer);
        glBufferData(GL_ARRAY_BUFFER, bufferData.size() * sizeof(float), bufferData.data(), GL_STATIC_DRAW);

        return newBuffer;
    }
}

using namespace Management;

std::unique_ptr<ActorDrawer> ActorDrawer::sInstancePtr = nullptr;

ActorDrawer::ActorDrawer()
{
    std::ifstream vertexShaderReadStream{ VertexShaderPath };
    std::ifstream fragmentShaderReadStream{ FragmentShaderPath };

    Shading::Shader vertexShader{ GL_VERTEX_SHADER, vertexShaderReadStream };
    Shading::Shader fragmentShader{ GL_FRAGMENT_SHADER, fragmentShaderReadStream };

    vertexShaderReadStream.close();
    fragmentShaderReadStream.close();

    vertexShader.Compile();
    fragmentShader.Compile();

    mProgramPtr = std::make_unique<Shading::Program>(
        std::initializer_list<Shading::Shader>({ std::move(vertexShader), std::move(fragmentShader) })
    );

    RegisterActor(&Object::Character::Instance());
}

ActorDrawer::~ActorDrawer()
{
    glDisableVertexAttribArray(PositionAttributeIndex);
    glDisableVertexAttribArray(ColorAttributeIndex);
}

ActorDrawer& ActorDrawer::Instance()
{
    if (!sInstancePtr)
    {
        sInstancePtr = std::unique_ptr<ActorDrawer>{ new ActorDrawer };
    }

    return *sInstancePtr;
}

void ActorDrawer::RegisterActor(Object::Actor* actorPtr)
{
    auto actorShapePtr = actorPtr->Shape();

    mRegisteredActors.insert(actorPtr);

    mVertexArrayMap.emplace(actorPtr, GenerateVao());
    mVertexBufferMap.emplace(actorPtr, GenerateVbo(actorShapePtr->Vertices()));
    mColorBufferMap.emplace(actorPtr, GenerateVbo(actorShapePtr->Colors()));

    glBindVertexArray(mVertexArrayMap[actorPtr]);

    glBindBuffer(GL_ARRAY_BUFFER, mVertexBufferMap[actorPtr]);
    glEnableVertexAttribArray(PositionAttributeIndex);
    glVertexAttribPointer(PositionAttributeIndex, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    glBindBuffer(GL_ARRAY_BUFFER, mColorBufferMap[actorPtr]);
    glEnableVertexAttribArray(ColorAttributeIndex);
    glVertexAttribPointer(ColorAttributeIndex, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    actorPtr->Initialize();
}

void ActorDrawer::ForceDeregisterActor(Object::Actor* actorPtr)
{
    glDeleteBuffers(1, &mVertexBufferMap[actorPtr]);
    glDeleteBuffers(1, &mColorBufferMap[actorPtr]);
    glDeleteVertexArrays(1, &mVertexArrayMap[actorPtr]);

    mRegisteredActors.erase(actorPtr);
    mVertexBufferMap.erase(actorPtr);
    mColorBufferMap.erase(actorPtr);
    mVertexArrayMap.erase(actorPtr);
}

void ActorDrawer::EnqueueDeregisterActor(Object::Actor* actorPtr)
{
    mDeregisteredQueue.push(actorPtr);
}


void ActorDrawer::Initialize()
{
    glUseProgram(mProgramPtr->Id());
}

#include <iostream>
void ActorDrawer::Draw()
{
    using namespace Object;

    GLuint matrixId = glGetUniformLocation(mProgramPtr->Id(), MatrixVariableName);

    while (!mDeregisteredQueue.empty())
    {
        ForceDeregisterActor(mDeregisteredQueue.front());
        mDeregisteredQueue.pop();
    }

    for (auto actorIterator = mRegisteredActors.begin(); actorIterator != mRegisteredActors.end(); /* noop */)
    {
        (*actorIterator)->Update();
        
        if (OrthographicCamera::Instance().IsOutOfCamera((*actorIterator)->Position()))
        {
            ForceDeregisterActor(*actorIterator++);
        }
        else
        {
            ++actorIterator;
        }
    }

    for (auto& actorPtr : mRegisteredActors)
    {
        glBindVertexArray(mVertexArrayMap[actorPtr]);

        auto matrix = OrthographicCamera::Instance().TransformationMatrix() * actorPtr->TransformationMatrix();
        glUniformMatrix4fv(matrixId, 1, GL_FALSE, &matrix[0][0]);

        size_t verticesSize = actorPtr->Shape()->Vertices().size();
        glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(verticesSize / 3));
    }
}