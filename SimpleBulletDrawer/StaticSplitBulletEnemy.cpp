#include "StaticSplitBulletEnemy.h"
#include "DirectedBullet.h"
#include "NWayBullet.h"
#include "Time.h"
#include "Square.h"

using namespace Object;

StaticSplitBulletEnemy::StaticSplitBulletEnemy(float firePeriod)
    : mFirePeriod{ firePeriod }
{
}

std::shared_ptr<Shape::IShape> StaticSplitBulletEnemy::Shape() const
{
    return std::make_shared<Shape::Square>(1.0f, glm::vec3{ 0.0f, 1.0f, 0.0f });
}

void StaticSplitBulletEnemy::Initialize()
{
    Position() += glm::vec3{ 0.0f, 8.0f, 0.0f };
}

void StaticSplitBulletEnemy::Update()
{
    using namespace Management;

    // Fill here!
}
