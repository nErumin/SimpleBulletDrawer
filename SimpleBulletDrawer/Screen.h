#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <memory>

namespace Management
{
    class Screen
    {
    public:
        static Screen& Instance();
    private:
        static std::unique_ptr<Screen> sInstancePtr;
    public:
        float AspectRatio() const noexcept;
        int& Width() noexcept;
        int& Height() noexcept;
    private:
        Screen();
    private:
        int mWidth;
        int mHeight;
    };
}

#endif // !_SCREEN_H_
