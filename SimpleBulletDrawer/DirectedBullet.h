#ifndef _DIRECTED_BULLET_H_
#define _DIRECTED_BULLET_H_

#include "Actor.h"
#include "glm/glm.hpp"

namespace Object
{
    class DirectedBullet : public Actor
    {
    public:
        DirectedBullet(float fireDegree, float bulletSpeed);
    public:
        glm::vec3& Velocity() noexcept;
        glm::vec3& Color() noexcept;

        std::shared_ptr<Shape::IShape> Shape() const override;
        void Initialize() override;
        void Update() override;
    private:
        glm::vec3 mVelocity{ 0, 0, 0 };
        glm::vec3 mBulletColor{ 1, 0, 1 };

        float mFireRadians;
        float mBulletSpeed;
    };
}


#endif // !_DIRECTED_BULLET_H_
