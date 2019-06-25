#include "Circle.h"
#include "glm/glm.hpp"

using namespace Shape;

namespace
{
    std::vector<float> MakeCircleVertices(float radius, float degreeStride)
    {
        std::vector<float> circlePoints;
        std::vector<float> vertices;

        for (float degree = 0.0f; degree < 360.f; degree += degreeStride)
        {
            circlePoints.push_back(radius * glm::cos(glm::radians(degree)));
            circlePoints.push_back(radius * glm::sin(glm::radians(degree)));
            circlePoints.push_back(0.0f);
        }

        for (size_t pointIndex = 0; pointIndex < circlePoints.size(); pointIndex += 3)
        {
            vertices.push_back(0.0f);
            vertices.push_back(0.0f);
            vertices.push_back(0.0f);
            
            vertices.push_back(circlePoints[pointIndex]);
            vertices.push_back(circlePoints[pointIndex + 1]);
            vertices.push_back(circlePoints[pointIndex + 2]);

            vertices.push_back(circlePoints[(pointIndex + 3) % circlePoints.size()]);
            vertices.push_back(circlePoints[(pointIndex + 4) % circlePoints.size()]);
            vertices.push_back(circlePoints[(pointIndex + 5) % circlePoints.size()]);
        }

        return vertices;
    }
}

Circle::Circle(float radius, float degreeStride, glm::vec3 circleColor)
    : mVertices{ MakeCircleVertices(radius, degreeStride) }
{
    for (size_t repeated = 0; repeated < mVertices.size() / 3; ++repeated)
    {
        mColors.push_back(circleColor.r);
        mColors.push_back(circleColor.g);
        mColors.push_back(circleColor.b);
    }
}

const std::vector<float>& Circle::Vertices() const
{
    return mVertices;
}

const std::vector<float>& Circle::Colors() const
{
    return mColors;
}