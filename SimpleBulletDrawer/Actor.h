#ifndef _ACTOR_H_
#define _ACTOR_H_

#include "glm/glm.hpp"
#include <memory>

namespace Shape
{
    class IShape;
}

namespace Object
{
    class Actor
    {
    public:
        virtual ~Actor();
    public:
        glm::vec3& Position() noexcept;
        glm::vec3& Scale() noexcept;
        glm::vec3& Rotation() noexcept;
        virtual std::shared_ptr<Shape::IShape> Shape() = 0;

        glm::mat4 TransformationMatrix() const;
    protected:
        virtual void Initialize() = 0;
        virtual void Update() = 0;
    private:
        glm::vec3 mPosition{ 0.0f, 0.0f, 0.0f };
        glm::vec3 mScale{ 1.0f, 1.0f, 1.0f };
        glm::vec3 mRotation{ 0.0f, 0.0f, 0.0f };
    };
}

#endif // !_ACTOR_H_
