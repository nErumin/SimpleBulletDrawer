#include "Screen.h"

using namespace Management;

std::unique_ptr<Screen> Screen::sInstancePtr = nullptr;

Screen& Screen::Instance()
{
    if (!sInstancePtr)
    {
        sInstancePtr = std::unique_ptr<Screen>(new Screen);
    }

    return *sInstancePtr;
}

Screen::Screen() = default;

int& Screen::Width() noexcept
{
    return mWidth;
}

int& Screen::Height() noexcept
{
    return mHeight;
}

float Screen::AspectRatio() const noexcept
{
    return static_cast<float>(mWidth) / mHeight;
}