#ifndef _DIRECTION_STAGE_FACTORY_H_
#define _DIRECTION_STAGE_FACTORY_H_

#include "StageFactory.h"

namespace Factory
{
    class DirectionStageFactory : public StageFactory
    {
    public:
        void Produce() override;
    private:
        size_t mCreatedEnemyCount = 0;
        double mCreationTimer = 0.0;
    };
}

#endif // !_DIRECTION_STAGE_FACTORY_H_
