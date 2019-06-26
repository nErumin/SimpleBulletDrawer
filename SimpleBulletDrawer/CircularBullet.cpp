#include "CircularBullet.h"
#include "NullShape.h"
#include "DirectedBullet.h"
#include "ActorDrawer.h"
#include "glm/glm.hpp"

using namespace Object;

CircularBullet::CircularBullet(float initialAngle, 
                               float centerSpeed, 
                               float radius, 
                               float radiusVelocity, 
                               float angularVelocity)
    : mCenterVelocity{ 0.0, -centerSpeed, 0.0f },
      mRadius{ radius },
      mRadiusVelocity{ radiusVelocity },
      mAngle{ initialAngle },
      mAngularVelocity{ angularVelocity }
{
}

float& CircularBullet::RadiusVelocity() noexcept
{
    return mRadiusVelocity;
}

glm::vec3& CircularBullet::CenterVelocity() noexcept
{
    return mCenterVelocity;
}

float& CircularBullet::AngularVelocity() noexcept
{
    return mAngularVelocity;
}

std::shared_ptr<Shape::IShape> CircularBullet::Shape() const
{
    return std::make_shared<Shape::NullShape>();
}

void CircularBullet::Initialize()
{
    auto parentActorPtr = ParentActor();

    if (parentActorPtr)
    {
        Position() = parentActorPtr->Position();
        Position().y += 0.5f;
    }

    mCirculationBullet = CreateChildActor<DirectedBullet>(0.0f, 0.0f);
    mCirculationBullet->Color() = Color();

    Management::ActorDrawer::Instance().RegisterActor(mCirculationBullet.get());
}

void CircularBullet::Update()
{
    // Fill here!
}