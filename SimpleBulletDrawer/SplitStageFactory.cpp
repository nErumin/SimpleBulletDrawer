#include "SplitStageFactory.h"
#include "StaticSplitBulletEnemy.h"
#include "ActorDrawer.h"
#include <memory>

using namespace Factory;

void SplitStageFactory::Produce()
{
    using namespace Management;

    if (mCreatedEnemyCount == 0)
    {
        auto newEnemyPtr = std::make_shared<Object::StaticSplitBulletEnemy>(0.5f);

        StartManageObject(newEnemyPtr);
        ActorDrawer::Instance().RegisterActor(newEnemyPtr.get());

        ++mCreatedEnemyCount;
    }
}