#include "CircularStageFactory.h"
#include "StaticCircularEnemy.h"
#include "ActorDrawer.h"
#include "glm/glm.hpp"

using namespace Factory;

void CircularStageFactory::Produce()
{
    using namespace Management;

    if (mCreatedEnemyCount == 0)
    {
        auto newEnemyPtr = std::make_shared<Object::StaticCircularEnemy>(0.4f, 0.0f);

        StartManageObject(newEnemyPtr);
        ActorDrawer::Instance().RegisterActor(newEnemyPtr.get());

        ++mCreatedEnemyCount;
    }
}