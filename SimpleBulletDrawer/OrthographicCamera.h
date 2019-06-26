#ifndef _ORTHOGRAPHIC_CAMERA_H_
#define _ORTHOGRAPHIC_CAMERA_H_

#include <memory>
#include "glm/glm.hpp"

namespace Object
{
    class OrthographicCamera
    {
    public:
        static OrthographicCamera& Instance();
    private:
        static std::unique_ptr<OrthographicCamera> sInstancePtr;
    public:
        glm::mat4 TransformationMatrix() const;
        bool IsOutOfCamera(const glm::vec3& position) const;

        glm::vec3& Position() noexcept;
        glm::vec3& CameraTarget() noexcept;
        glm::vec3& LocalUp() noexcept;

        glm::vec2& PlaneX() noexcept;
        glm::vec2& PlaneY() noexcept;
        glm::vec2& PlaneZ() noexcept;
    private:
        OrthographicCamera();
    private:
        glm::vec3 mPosition{ 0, 0, 0 };
        glm::vec3 mCameraTarget{ 0, 0, 0 };
        glm::vec3 mLocalUp{ 0, 1, 0 };

        glm::vec2 mPlaneX{ -1, 1 };
        glm::vec2 mPlaneY{ -1, 1 };
        glm::vec2 mPlaneZ{ -1, 1 };
    };
}

#endif // !_ORTHOGRAPHIC_CAMERA_H_
