#include "Program.h"
#include "GLEW/glew.h"
#include "Shader.h"

using namespace Shading;

namespace
{
    void LinkProgram(int programId, const std::initializer_list<Shader>& shaders)
    {
        for (const auto& shader : shaders)
        {
            glAttachShader(programId, shader.Id());
        }

        glLinkProgram(programId);

        for (const auto& shader : shaders)
        {
            glDetachShader(programId, shader.Id());
        }
    }
}

Program::Program(std::initializer_list<Shader> shaders)
    : mProgramId{ glCreateProgram() }
{
    LinkProgram(mProgramId, shaders);
}

Program::Program(Program&& otherProgram)
    : mProgramId{ otherProgram.mProgramId }
{
}

Program& Program::operator=(Program&& otherProgram)
{
    mProgramId = otherProgram.mProgramId;

    return *this;
}

Program::~Program()
{
    glDeleteProgram(mProgramId);
}

unsigned int Program::Id() const noexcept
{
    return mProgramId;
}