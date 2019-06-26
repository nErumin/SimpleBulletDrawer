#include "NWayStageFactory.h"
#include "StaticEnemy.h"
#include "ActorDrawer.h"

using namespace Factory;

void NWayStageFactory::Produce()
{
    using namespace Management;

    if (mCreatedEnemyCount == 0)
    {
        auto newEnemyPtr = std::make_shared<Object::StaticEnemy>(0.5f);

        StartManageObject(newEnemyPtr);
        ActorDrawer::Instance().RegisterActor(newEnemyPtr.get());
        
        ++mCreatedEnemyCount;
    }
}