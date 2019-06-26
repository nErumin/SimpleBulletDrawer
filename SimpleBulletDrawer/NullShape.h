#ifndef _NULL_SHAPE_H_
#define _NULL_SHAPE_H_

#include "IShape.h"

namespace Shape
{
    class NullShape : public IShape
    {
    public:
        const std::vector<float>& Vertices() const override;
        const std::vector<float>& Colors() const override;
    private:
        std::vector<float> mEmptyVector;
    };
}

#endif // !_NULL_SHAPE_H_
