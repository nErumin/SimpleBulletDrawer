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

    mBulletCreationTimer += Time::DeltaTime();

    if (mBulletCreationTimer > mFirePeriod)
    {
        auto leftBulletPtr = CreateChildActor<DirectedBullet>(-45.0f, 0.05f);
        leftBulletPtr->Color() = glm::vec3{ 0.4, 0.4, 0.7 };

        auto rightBulletPtr = CreateChildActor<DirectedBullet>(-135.0f, 0.05f);
        rightBulletPtr->Color() = glm::vec3{ 0, 1, 1 };

        ActorDrawer::Instance().RegisterActor(leftBulletPtr.get());
        ActorDrawer::Instance().RegisterActor(rightBulletPtr.get());

        mCreatedDirectBullets.emplace(leftBulletPtr, Time::LastRenderedTime());
        mCreatedDirectBullets.emplace(rightBulletPtr, Time::LastRenderedTime());

        mBulletCreationTimer -= mFirePeriod;
    }

    for (auto bulletIterator = mCreatedDirectBullets.begin();
        bulletIterator != mCreatedDirectBullets.end();
        /* noop */)
    {
        if (Time::LastRenderedTime() - bulletIterator->second >= 1.0f)
        {
            auto directedBullet = bulletIterator->first;
            auto nWayBullet = directedBullet->CreateChildActor<NWayBullet>(5, -90.0f, 30.0f, 0.05f);

            nWayBullet->Position() = directedBullet->Position();
            nWayBullet->Color() = directedBullet->Color();

            ActorDrawer::Instance().EnqueueDeregisterActor(directedBullet.get());
            ActorDrawer::Instance().RegisterActor(nWayBullet.get());

            bulletIterator = mCreatedDirectBullets.erase(bulletIterator);
        }
        else
        {
            ++bulletIterator;
        }
    }
}
