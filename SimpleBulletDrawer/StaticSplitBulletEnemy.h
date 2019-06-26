#ifndef _STATIC_SPLIT_BULLET_ENEMY_H_
#define _STATIC_SPLIT_BULLET_ENEMY_H_

#include "Actor.h"
#include <unordered_map>

namespace Object
{
    class StaticSplitBulletEnemy : public Actor
    {
    public:
        StaticSplitBulletEnemy(float firePeriod);
    public:
        std::shared_ptr<Shape::IShape> Shape() const override;
        void Initialize() override;
        void Update() override;
    private:
        float mFirePeriod = 0.0f;
        double mBulletCreationTimer = 0.0;

        std::unordered_map<std::shared_ptr<Object::Actor>, double> mCreatedDirectBullets;
    };
}


#endif // !_STATIC_SPLIT_BULLET_ENEMY_H_
