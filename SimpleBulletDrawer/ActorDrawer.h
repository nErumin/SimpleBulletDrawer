#ifndef _ACTOR_DRAWER_H_
#define _ACTOR_DRAWER_H_

#include <unordered_set>
#include <unordered_map>
#include <memory>
#include <queue>

namespace Object
{
    class Actor;
    class OrthographicCamera;
}

namespace Shading
{
    class Program;
}

namespace Management
{
    class ActorDrawer
    {
    public:
        static ActorDrawer& Instance();
    private:
        static std::unique_ptr<ActorDrawer> sInstancePtr;
    public:     
        ~ActorDrawer();

        void RegisterActor(Object::Actor* actorPtr);
        void ForceDeregisterActor(Object::Actor* actorPtr);
        void EnqueueDeregisterActor(Object::Actor* actorPtr);

        void Initialize();
        void Draw();
    private:
        ActorDrawer();
    private:
        std::unordered_set<Object::Actor*> mRegisteredActors;

        std::unordered_map<Object::Actor*, unsigned> mVertexArrayMap;
        std::unordered_map<Object::Actor*, unsigned> mVertexBufferMap;
        std::unordered_map<Object::Actor*, unsigned> mColorBufferMap;
        
        std::unique_ptr<Shading::Program> mProgramPtr;
        std::queue<Object::Actor*> mDeregisteredQueue;
    };
}

#endif // !_ACTOR_DRAWER_H_
