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

    mBulletCreationTimer += Time::DeltaTime();

    if (mBulletCreationTimer > mFirePeriod)
    {
        auto blueBulletPtr = CreateChildActor<CircularBullet>(mFireAngle, 0.0f, 0.01f, 0.0025f, 0.25f);
        blueBulletPtr->Color() = glm::vec3{ 0.3f, 0.7f, 0.8f };

        auto redBulletPtr = CreateChildActor<CircularBullet>(90.0f + mFireAngle, 0.0f, 0.01f, 0.0025f, 0.25f);
        redBulletPtr->Color() = glm::vec3{ 0.7f, 0.7f, 0.3f };

        ActorDrawer::Instance().RegisterActor(blueBulletPtr.get());
        ActorDrawer::Instance().RegisterActor(redBulletPtr.get());

        mFireAngle += 5.0f;
        mBulletCreationTimer -= mFirePeriod;
    }
}