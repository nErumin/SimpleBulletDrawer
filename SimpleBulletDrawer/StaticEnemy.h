#ifndef _STATIC_ENEMY_H_
#define _STATIC_ENEMY_H_

#include "Actor.h"

namespace Object
{
    class StaticEnemy : public Actor
    {
    public:
        StaticEnemy(float firePeriod);
    public:
        std::shared_ptr<Shape::IShape> Shape() const override;
        void Initialize() override;
        void Update() override;
    private:
        float mFirePeriod = 0.0f;
        double mBulletCreationTimer = 0.0;
        size_t mBulletCreatedCount = 0;
    };
}

#endif // !_STATIC_ENEMY_H_
