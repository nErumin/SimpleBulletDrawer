#include "OrthographicCamera.h"
#include "Screen.h"

#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/ext/matrix_clip_space.hpp"

using namespace Object;

std::unique_ptr<OrthographicCamera> OrthographicCamera::sInstancePtr = nullptr;

OrthographicCamera& Object::OrthographicCamera::Instance()
{
    if (!sInstancePtr)
    {
        sInstancePtr = std::unique_ptr<OrthographicCamera>(new OrthographicCamera);
    }

    return *sInstancePtr;
}

OrthographicCamera::OrthographicCamera() = default;

glm::mat4 OrthographicCamera::TransformationMatrix() const
{
    auto viewingMatrix = glm::lookAt(mPosition, mCameraTarget, mLocalUp);
    
    float aspectRatio = Management::Screen::Instance().AspectRatio();
    auto projectionMatrix = glm::ortho(mPlaneX.x * aspectRatio, mPlaneX.y * aspectRatio, 
                                       mPlaneY.x, mPlaneY.y, 
                                       mPlaneZ.x, mPlaneZ.y);

    return projectionMatrix * viewingMatrix;
}

bool OrthographicCamera::IsOutOfCamera(const glm::vec3& position) const
{
#pragma message ("OrthgraphicCamera.cpp::IsOutOfCamera ==> Does not consider a camera's target position...")
    auto xBoundary = glm::vec2{ mPosition.x, 0.0f } + mPlaneX;
    auto yBoundary = glm::vec2{ mPosition.y, 0.0f } + mPlaneY;
    auto zBoundary = glm::vec2{ mPosition.z, 0.0f } - mPlaneZ;

    return position.x < xBoundary.x || position.x > xBoundary.y ||
           position.y < yBoundary.x || position.y > yBoundary.y ||
           position.z > zBoundary.x || position.z < zBoundary.y;
}

glm::vec3& OrthographicCamera::Position() noexcept
{
    return mPosition;
}

glm::vec3& OrthographicCamera::CameraTarget() noexcept
{
    return mCameraTarget;
}

glm::vec3& OrthographicCamera::LocalUp() noexcept
{
    return mLocalUp;
}

glm::vec2& OrthographicCamera::PlaneX() noexcept
{
    return mPlaneX;
}

glm::vec2& OrthographicCamera::PlaneY() noexcept
{
    return mPlaneY;
}

glm::vec2& OrthographicCamera::PlaneZ() noexcept
{
    return mPlaneZ;
}