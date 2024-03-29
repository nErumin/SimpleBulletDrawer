#include "NWayBullet.h"
#include "DirectedBullet.h"
#include "NullShape.h"

#include <list>

using namespace Object;

namespace
{
    std::list<float> MakeBulletDegress(size_t bulletSteps, float centerDegree, float rotationDegree)
    {
        std::list<float> bulletDegrees;

        if (bulletSteps % 2 == 0)
        {
            bulletDegrees.push_back(centerDegree - rotationDegree / 2.0f);
            bulletDegrees.push_back(centerDegree + rotationDegree / 2.0f);
        }
        else
        {
            bulletDegrees.push_back(centerDegree);
        }

        while (bulletDegrees.size() != bulletSteps)
        {
            bulletDegrees.push_front(bulletDegrees.front() - rotationDegree);
            bulletDegrees.push_back(bulletDegrees.back() + rotationDegree);
        }

        return bulletDegrees;
    }
}

NWayBullet::NWayBullet(size_t bulletSteps, float centerDegree, float rotationDegree, float bulletSpeed)
    : mBulletSteps{ bulletSteps },
      mCenterDegree{ centerDegree },
      mRotationDegree{ rotationDegree },
      mBulletSpeed{ bulletSpeed }
{
    Color() = glm::vec3{ 1, 0, 1 };
}

glm::vec3& NWayBullet::Velocity() noexcept
{
    return mVelocity;
}

std::shared_ptr<Shape::IShape> NWayBullet::Shape() const
{
    return std::make_shared<Shape::NullShape>();
}

void NWayBullet::Initialize()
{
    auto parentActorPtr = ParentActor();

    if (parentActorPtr)
    {
        Position() = parentActorPtr->Position();
    }

    auto bulletDegrees = MakeBulletDegress(mBulletSteps, mCenterDegree, mRotationDegree);

    for (float& bulletDegree : bulletDegrees)
    {
        auto bulletPtr = CreateChildActor<DirectedBullet>(bulletDegree, mBulletSpeed);
        bulletPtr->Color() = Color();

        Management::ActorDrawer::Instance().RegisterActor(bulletPtr.get());
    }
}

void NWayBullet::Update()
{
    auto parentActorPtr = ParentActor();

    if (parentActorPtr)
    {
        Position() = parentActorPtr->Position();
    }
}