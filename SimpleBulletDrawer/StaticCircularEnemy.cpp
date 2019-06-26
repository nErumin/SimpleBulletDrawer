#include "StaticCircularEnemy.h"
#include "Square.h"
#include "ActorDrawer.h"
#include "CircularBullet.h"
#include "Time.h"

using namespace Object;

StaticCircularEnemy::StaticCircularEnemy(float firePeriod, float fireAngle)
    : mFirePeriod{ firePeriod },
      mFireAngle{ fireAngle }
{
}

std::shared_ptr<Shape::IShape> StaticCircularEnemy::Shape() const
{
    return std::make_shared<Shape::Square>(1.0f, glm::vec3{ 0.0f, 1.0f, 0.0f });
}

void StaticCircularEnemy::Initialize()
{
    Position() = glm::vec3{ 0.0f, 0.0f, 0.0f };
}

void StaticCircularEnemy::Update()
{
    using namespace Management;

    // Fill here!
}