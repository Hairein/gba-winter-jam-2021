#include "vector_helper.h"

namespace mks
{
    VectorHelper::VectorHelper()
    {
    }

    VectorHelper::~VectorHelper()
    {
    }

    bn::fixed_point VectorHelper::get_rotated_unit_vector_x(int angle)
    {
        return rotated_unit_vectors_x[angle];
    }

    bn::fixed_point VectorHelper::get_rotated_unit_vector_y(int angle)
    {
        return rotated_unit_vectors_y[angle];
    }
}