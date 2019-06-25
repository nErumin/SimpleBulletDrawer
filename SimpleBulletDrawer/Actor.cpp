#include "Actor.h"
#include "glm/gtx/transform.hpp"

using namespace Object;

Actor::~Actor() = default;

glm::vec3& Actor::Position() noexcept
{
    return mPosition;
}

glm::vec3& Actor::Scale() noexcept
{
    return mScale;
}

glm::vec3& Actor::Rotation() noexcept
{
    return mRotation;
}

glm::mat4 Actor::TransformationMatrix() const
{
    glm::mat4 transformationMatrix{ 1.0f };

    // Scale
    transformationMatrix = glm::scale(transformationMatrix, mScale);

    // Rotate
    transformationMatrix = glm::rotate(transformationMatrix, glm::radians(mRotation.x), glm::vec3{ 1, 0, 0 });


    transformationMatrix = glm::rotate(transformationMatrix, glm::radians(mRotation.y), glm::vec3{ 0, 1, 0 });
    transformationMatrix = glm::rotate(transformationMatrix, glm::radians(mRotation.z), glm::vec3{ 0, 0, 1 });

    // Translate
    transformationMatrix = glm::translate(transformationMatrix, mPosition);

    return transformationMatrix;
}