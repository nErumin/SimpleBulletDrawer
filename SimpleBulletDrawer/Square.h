#ifndef _SQUARE_H_
#define _SQUARE_H_

#include "IShape.h"
#include "glm/glm.hpp"

namespace Shape
{
    class Square : public IShape
    {
    public:
        Square(float sideLength, glm::vec3 squareColor);
    public:
        const std::vector<float>& Vertices() const override;
        const std::vector<float>& Colors() const override;
    private:
        std::vector<float> mVertices;
        std::vector<float> mColors;
    };
}

#endif // !_SQUARE_H_
