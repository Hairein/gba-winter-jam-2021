#include "bn_math.h"

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

    bn::fixed_point VectorHelper::rotate_vector(bn::fixed_point& input, bn::fixed& angle)
    {
        bn::fixed_point result;
        result.set_x(input.x() * degrees_lut_cos(angle) - input.y() * degrees_lut_sin(angle));
        result.set_y(input.x() * degrees_lut_sin(angle) + input.y() * degrees_lut_cos(angle));
        return result;
    }
}