#include "NullShape.h"
#include "glm/glm.hpp"

using namespace Shape;

const std::vector<float>& NullShape::Vertices() const
{
    return mEmptyVector;
}

const std::vector<float>& NullShape::Colors() const
{
    return mEmptyVector;
}