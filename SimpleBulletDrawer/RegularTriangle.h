#ifndef _REGULAR_TRIANGLE_H_
#define _REGULAR_TRIANGLE_H_

#include "IShape.h"
#include "glm/glm.hpp"

namespace Shape
{
    class RegularTriangle : public IShape
    {
    public:
        RegularTriangle(float sideLength, glm::vec3 triangleColor);
    public:
        const std::vector<float>& Vertices() const override;
        const std::vector<float>& Colors() const override;
    private:
        std::vector<float> mVertices;
        std::vector<float> mColors;
    };
}

#endif // !_REGULAR_TRIANGLE_H_
