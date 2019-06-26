#ifndef _ACTOR_H_
#define _ACTOR_H_

#include "ActorDrawer.h"
#include "glm/glm.hpp"
#include <memory>
#include <unordered_set>

namespace Shape
{
    class IShape;
}

namespace Object
{
    class Actor
    {
    public:
        Actor();
        virtual ~Actor();
    public:
        glm::vec3& Position() noexcept;
        glm::vec3& Scale() noexcept;
        glm::vec3& Rotation() noexcept;

        glm::mat4 TransformationMatrix() const;
        
        virtual std::shared_ptr<Shape::IShape> Shape() const = 0;
        virtual void Initialize() = 0;
        virtual void Update() = 0;
    protected:
        template <typename TActor, typename... Args>
        std::shared_ptr<TActor> CreateChildActor(Args&&... args);
     
        std::unordered_set<std::shared_ptr<Actor>>& ChildActors() noexcept;
        Actor* ParentActor() noexcept;
    private:
        glm::vec3 mPosition{ 0.0f, 0.0f, 0.0f };
        glm::vec3 mScale{ 1.0f, 1.0f, 1.0f };
        glm::vec3 mRotation{ 0.0f, 0.0f, 0.0f };

        Actor* mParentActor = nullptr;
        std::unordered_set<std::shared_ptr<Actor>> mChildActors;
    };

    template<typename TActor, typename...Args>
    inline std::shared_ptr<TActor> Actor::CreateChildActor(Args&&... args)
    {
        auto actorPtr = std::make_shared<TActor>(std::forward<Args>(args)...);

        actorPtr->mParentActor = this;
        mChildActors.insert(actorPtr);

        return actorPtr;
    }
}

#endif // !_ACTOR_H_
