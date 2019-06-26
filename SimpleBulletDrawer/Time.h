#ifndef _TIME_H_

namespace Management
{
    class Time
    {
    public:
        static double& DeltaTime() noexcept;
        static double& LastRenderedTime() noexcept;
    private:
        static double sDeltaTime;
        static double sLastRenderedTime;
    private:
        Time();
    };
}

#endif // !_TIME_H_
