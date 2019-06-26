#include "DirectionStageFactory.h"
#include "Time.h"
#include "ForwardingEnemy.h"
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

void DirectionStageFactory::Produce()
{
    using namespace Management;

    if (mCreatedEnemyCount >= CreationCountLimit)
    {
        return;
    }

    mCreationTimer += Time::DeltaTime();

    if (mCreationTimer >= CreationPeriod)
    {
        auto newEnemyPtr = std::make_shared<Object::ForwardingEnemy>(0.01f, 2.0f);
        newEnemyPtr->Position() += EnemyTranslationVector;

        StartManageObject(newEnemyPtr);
        ActorDrawer::Instance().RegisterActor(newEnemyPtr.get());

        EnemyTranslationVector.x += 2.5f;
        ++mCreatedEnemyCount;

        mCreationTimer -= CreationPeriod;
    }
}