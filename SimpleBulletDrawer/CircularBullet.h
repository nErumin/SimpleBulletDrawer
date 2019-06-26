#ifndef _CIRCULAR_BULLET_H_
#define _CIRCULAR_BULLET_H_

#include "Actor.h"
#include "glm/glm.hpp"

#include <unordered_map>
#include <memory>

namespace Object
{
    class DirectedBullet;

    class CircularBullet : public Actor
    {
    public:
        CircularBullet(float initialAngle, float centerSpeed, float radius, float radiusVelocity, float angularVelocity);
    public:
        glm::vec3& CenterVelocity() noexcept;
        float& AngularVelocity() noexcept;
        float& RadiusVelocity() noexcept;

        std::shared_ptr<Shape::IShape> Shape() const override;
        void Initialize() override;
        void Update() override;
    private:
        glm::vec3 mCenterVelocity{ 0, 0, 0 };

        float mRadius;
        float mRadiusVelocity;
        float mAngle;
        float mAngularVelocity;

        std::shared_ptr<DirectedBullet> mCirculationBullet;
    };
}


#endif // !_CIRCULAR_BULLET_H_
