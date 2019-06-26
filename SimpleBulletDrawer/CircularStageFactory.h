#ifndef _CIRCULAR_STAGE_FACTORY_H_
#define _CIRCULAR_STAGE_FACTORY_H_

#include "StageFactory.h"

namespace Factory
{
    class CircularStageFactory : public StageFactory
    {
    public:
        void Produce() override;
    private:
        size_t mCreatedEnemyCount = 0;
    };
}

#endif // !_CIRCULAR_STAGE_FACTORY_H_
