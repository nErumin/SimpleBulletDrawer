#include "Square.h"
#include "glm/glm.hpp"

using namespace Shape;

namespace
{
    std::vector<float> MakeSquareVertices(float sideLength)
    {
        std::vector<float> vertices;

        // Upper-left triangle (CCW)
        vertices.push_back(-sideLength / 2.0f);
        vertices.push_back(0.0f);
        vertices.push_back(0.0f);

        vertices.push_back(sideLength / 2.0f);
        vertices.push_back(sideLength);
        vertices.push_back(0.0f);

        vertices.push_back(-sideLength / 2.0f);
        vertices.push_back(sideLength);
        vertices.push_back(0.0f);

        // Lower-right triangle (CCW)
        vertices.push_back(-sideLength / 2.0f);
        vertices.push_back(0.0f);
        vertices.push_back(0.0f);

        vertices.push_back(sideLength / 2.0f);
        vertices.push_back(0.0f);
        vertices.push_back(0.0f);

        vertices.push_back(sideLength / 2.0f);
        vertices.push_back(sideLength);
        vertices.push_back(0.0f);

        return vertices;
    }
}

Square::Square(float sideLength, glm::vec3 squareColor)
    : mVertices{ MakeSquareVertices(sideLength) }
{
    for (size_t repeated = 0; repeated < mVertices.size() / 3; ++repeated)
    {
        mColors.push_back(squareColor.r);
        mColors.push_back(squareColor.g);
        mColors.push_back(squareColor.b);
    }
}

const std::vector<float>& Square::Vertices() const
{
    return mVertices;
}

const std::vector<float>& Square::Colors() const
{
    return mColors;
}