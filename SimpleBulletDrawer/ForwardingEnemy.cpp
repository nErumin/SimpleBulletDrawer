#include "ForwardingEnemy.h"
#include "DirectedBullet.h"
#include "Time.h"
#include "Square.h"

using namespace Object;

ForwardingEnemy::ForwardingEnemy(float moveSpeed, float firePeriod)
    : mVelocity{ 0, -moveSpeed, 0 },
      mFirePeriod{ firePeriod }
{
}

glm::vec3& ForwardingEnemy::Velocity() noexcept
{
    return mVelocity;
}

std::shared_ptr<Shape::IShape> ForwardingEnemy::Shape() const
{
    return std::make_shared<Shape::Square>(1.0f, glm::vec3{ 0.0f, 1.0f, 0.0f });
}

void ForwardingEnemy::Initialize()
{
}

void ForwardingEnemy::Update()
{
    using namespace Management;

    mBulletCreationTimer += Time::DeltaTime();

    if (mBulletCreationTimer > mFirePeriod)
    {
        auto actorPtr = CreateChildActor<DirectedBullet>(-90.0f, 0.05f);
        ActorDrawer::Instance().RegisterActor(actorPtr.get());

        mBulletCreationTimer -= mFirePeriod;
    }

    Position() += Velocity();
}
