#ifndef _NWAY_STAGE_FACTORY_H_
#define _NWAY_STAGE_FACTORY_H_

#include "StageFactory.h"

namespace Factory
{
    class NWayStageFactory : public StageFactory
    {
    public:
        void Produce() override;
    private:
        size_t mCreatedEnemyCount = 0;
    };
}

#endif // !_NWAY_STAGE_FACTORY_H_
