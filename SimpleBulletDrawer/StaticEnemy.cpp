#include "StaticEnemy.h"
#include "NWayBullet.h"
#include "Time.h"
#include "Square.h"

using namespace Object;

StaticEnemy::StaticEnemy(float firePeriod)
    : mFirePeriod{ firePeriod }
{
}

std::shared_ptr<Shape::IShape> StaticEnemy::Shape() const
{
    return std::make_shared<Shape::Square>(1.0f, glm::vec3{ 0.0f, 1.0f, 0.0f });
}

void StaticEnemy::Initialize()
{
    Position() += glm::vec3{ 0.0f, 8.0f, 0.0f };
}

void StaticEnemy::Update()
{
    using namespace Management;

    mBulletCreationTimer += Time::DeltaTime();

    if (mBulletCreationTimer > mFirePeriod)
    {
        auto bulletColor = mBulletCreatedCount % 2 == 0 ?
            glm::vec3{ 1, 1, 0 } :
            glm::vec3{ 0, 1, 1 };

        size_t bulletSteps = mBulletCreatedCount % 2 == 0 ?
            5 :
            6;

        auto actorPtr = CreateChildActor<NWayBullet>(bulletSteps, -20.0f, 30.0f, 0.05f);
        actorPtr->Color() = bulletColor;
        
        ActorDrawer::Instance().RegisterActor(actorPtr.get());

        mBulletCreationTimer -= mFirePeriod;
        ++mBulletCreatedCount;
    }
}
