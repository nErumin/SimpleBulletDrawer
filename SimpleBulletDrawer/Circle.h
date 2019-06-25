#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "IShape.h"
#include "glm/glm.hpp"

namespace Shape
{
    class Circle : public IShape
    {
    public:
        Circle(float radius, float degreeStride, glm::vec3 circleColor);
    public:
        const std::vector<float>& Vertices() const override;
        const std::vector<float>& Colors() const override;
    private:
        std::vector<float> mVertices;
        std::vector<float> mColors;
    };
}

#endif // !_CIRCLE_H_
