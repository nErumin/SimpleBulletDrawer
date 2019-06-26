#ifndef _NWAY_BULLET_H_
#define _NWAY_BULLET_H_

#include "Actor.h"

namespace Object
{
    class NWayBullet : public Actor
    {
    public:
        NWayBullet(size_t bulletSteps, float centerDegree, float rotationDegree, float bulletSpeed);
    public:
        glm::vec3& Velocity() noexcept;
        glm::vec3& Color() noexcept;

        std::shared_ptr<Shape::IShape> Shape() const override;
        void Initialize() override;
        void Update() override;
    private:
        glm::vec3 mVelocity{ 0, 0, 0 };
        glm::vec3 mBulletColor{ 1, 0, 1 };

        size_t mBulletSteps;
        float mCenterDegree;
        float mRotationDegree;
        float mBulletSpeed;
    };
}

#endif // !_NWAY_BULLET_H_
