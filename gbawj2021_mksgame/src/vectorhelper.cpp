#include "vectorhelper.h"

namespace mks
{
    VectorHelper::VectorHelper()
    {
    }

    VectorHelper::~VectorHelper()
    {
    }

    bn::fixed_point VectorHelper::getRotatedUnitVectorX(int angle)
    {
        return rotated_unit_vectors_x[angle];
    }

    bn::fixed_point VectorHelper::getRotatedUnitVectorY(int angle)
    {
        return rotated_unit_vectors_y[angle];
    }
}