#ifndef _STATIC_CIRCULAR_ENEMY_H_
#define _STATIC_CIRCULAR_ENEMY_H_

#include "Actor.h"

namespace Object
{
    class StaticCircularEnemy : public Actor
    {
    public:
        StaticCircularEnemy(float firePeriod, float fireAngle);
    public:
        std::shared_ptr<Shape::IShape> Shape() const override;
        void Initialize() override;
        void Update() override;
    private:
        float mFirePeriod;
        float mFireAngle = 0.0f;
        double mBulletCreationTimer = 0.0;
    };
}

#endif // !_STATIC_CIRCULAR_ENEMY_H_
