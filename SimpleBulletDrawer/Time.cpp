#include "Time.h"

using namespace Management;

double Time::sDeltaTime = 0.0f;
double Time::sLastRenderedTime = 0.0f;

double& Time::DeltaTime() noexcept
{
    return sDeltaTime;
}

double& Time::LastRenderedTime() noexcept
{
    return sLastRenderedTime;
}