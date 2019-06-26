#ifndef _STAGE_FACTORY_H_
#define _STAGE_FACTORY_H_

#include <vector>
#include <memory>

namespace Object
{
    class Actor;
}

namespace Factory
{
    class StageFactory
    {
    public:
        virtual void Produce() = 0;
    protected:
        void StartManageObject(std::shared_ptr<Object::Actor> actorPtr)
        {
            managedActors.push_back(actorPtr);
        }
    private:
        std::vector<std::shared_ptr<Object::Actor>> managedActors;
    };
}

#endif // !_ISTAGE_FACTORY_H_
