#include "NWayBullet.h"
#include "DirectedBullet.h"
#include "NullShape.h"

#include <list>

using namespace Object;

NWayBullet::NWayBullet(size_t bulletSteps, float centerDegree, float rotationDegree, float bulletSpeed)
    : mBulletSteps{ bulletSteps },
      mCenterDegree{ centerDegree },
      mRotationDegree{ rotationDegree },
      mBulletSpeed{ bulletSpeed }
{
    Color() = glm::vec3{ 1, 0, 1 };
}

glm::vec3& NWayBullet::Velocity() noexcept
{
    return mVelocity;
}

std::shared_ptr<Shape::IShape> NWayBullet::Shape() const
{
    return std::make_shared<Shape::NullShape>();
}

void NWayBullet::Initialize()
{
    // Fill here!
}

void NWayBullet::Update()
{
    // Fill here!
}
