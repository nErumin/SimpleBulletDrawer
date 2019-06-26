#ifndef _SPLIT_STAGE_FACTORY_H_
#define _SPLIT_STAGE_FACTORY_H_

#include "StageFactory.h"

namespace Factory
{
    class SplitStageFactory : public StageFactory
    {
    public:
        void Produce() override;
    private:
        size_t mCreatedEnemyCount = 0;
    };
}

#endif // !_SPLIT_STAGE_FACTORY_H_
