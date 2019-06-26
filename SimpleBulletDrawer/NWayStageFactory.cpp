#include "NWayStageFactory.h"
#include "Time.h"
#include "StaticEnemy.h"
#include "ActorDrawer.h"
#include "glm/glm.hpp"
#include <vector>
#include <utility>

using namespace Factory;

namespace
{
    glm::vec3 EnemyTranslationVector{ -5.0f, 8.0f, 0.0f };
    constexpr float CreationPeriod = 3.0f;
    constexpr size_t CreationCountLimit = 5;
}

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