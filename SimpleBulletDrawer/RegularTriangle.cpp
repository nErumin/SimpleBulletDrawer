#include "RegularTriangle.h"
#include "glm/glm.hpp"

using namespace Shape;

namespace
{
    std::vector<float> MakeTriangleVertices(float sideLength)
    {
        std::vector<float> vertices;

        vertices.push_back(-sideLength / 2.0f);
        vertices.push_back(0.0f);
        vertices.push_back(0.0f);

        vertices.push_back(sideLength / 2.0f);
        vertices.push_back(0.0f);
        vertices.push_back(0.0f);

        glm::vec2 apexVertex{
            sideLength * glm::cos(glm::radians(60.0f)) - (sideLength / 2.0f),
            sideLength * glm::sin(glm::radians(60.0f))
        };

        vertices.push_back(apexVertex.x);
        vertices.push_back(apexVertex.y);
        vertices.push_back(0.0f);

        return vertices;
    }
}

RegularTriangle::RegularTriangle(float sideLength, glm::vec3 triangleColor)
    : mVertices{ MakeTriangleVertices(sideLength) }
{
    for (size_t repeated = 0; repeated < mVertices.size() / 3; ++repeated)
    {
        mColors.push_back(triangleColor.r);
        mColors.push_back(triangleColor.g);
        mColors.push_back(triangleColor.b);
    }
}

const std::vector<float>& RegularTriangle::Vertices() const
{
    return mVertices;
}

const std::vector<float>& RegularTriangle::Colors() const
{
    return mColors;
}