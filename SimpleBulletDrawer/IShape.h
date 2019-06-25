#ifndef _ISHAPE_H_
#define _ISHAPE_H_

#include <vector>

namespace Shape
{
    class IShape
    {
    public:
        IShape() = default;
        virtual ~IShape() = default;
    public:
        virtual const std::vector<float>& Vertices() const = 0;
        virtual const std::vector<float>& Colors() const = 0;
    };
}

#endif // !_ISHAPE_H_
