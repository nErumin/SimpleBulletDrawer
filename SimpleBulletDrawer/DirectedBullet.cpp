#include "DirectedBullet.h"
#include "Circle.h"

using namespace Object;

DirectedBullet::DirectedBullet(float fireDegree, float bulletSpeed)
    : mFireRadians{ glm::radians(fireDegree) },
      mBulletSpeed{ bulletSpeed }
{
    Color() = glm::vec3{ 1, 0, 1 };
}

glm::vec3& DirectedBullet::Velocity() noexcept
{
    return mVelocity;
}

std::shared_ptr<Shape::IShape> DirectedBullet::Shape() const
{
    return std::make_shared<Shape::Circle>(0.25f, 45.0f, Color());
}

void DirectedBullet::Initialize()
{
    // Fill here!
}

void DirectedBullet::Update()
{
    // Fill here!
}