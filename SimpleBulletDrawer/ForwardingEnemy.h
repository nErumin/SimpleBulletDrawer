#ifndef _FORWARDING_ENEMY_H_
#define _FORWARDING_ENEMY_H_

#include "Actor.h"

namespace Object
{
    class ForwardingEnemy : public Actor
    {
    public:
        ForwardingEnemy(float moveSpeed, float firePeriod);
    public:
        glm::vec3& Velocity() noexcept;

        std::shared_ptr<Shape::IShape> Shape() const override;
        void Initialize() override;
        void Update() override;
    private:
        glm::vec3 mVelocity{ 0, 0, 0 };
        
        float mFirePeriod;
        double mBulletCreationTimer = 0.0;
    };
}

#endif // !_FORWARDING_ENEMY_H_
