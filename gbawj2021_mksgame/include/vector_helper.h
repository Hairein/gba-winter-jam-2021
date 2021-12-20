#ifndef MKS_VECTORHELPER_H
#define MKS_VECTORHELPER_H

#include "bn_fixed.h"
#include "bn_fixed_point.h"

namespace mks
{
    class VectorHelper
    {
    public:
        VectorHelper();
        ~VectorHelper();

        bn::fixed_point get_rotated_unit_vector_x(int angle);
        bn::fixed_point get_rotated_unit_vector_y(int angle);
    
        bn::fixed_point rotate_vector(bn::fixed_point& input, bn::fixed& angle);

        void calculate_sprite_position_angle(bn::fixed_point& map_center, bn::fixed& map_yaw, 
            bn::fixed_point& map_entity_position, bn::fixed& map_entity_angle, 
            bn::fixed_point& sprite_position, bn::fixed& sprite_angle);

        int calculate_sprite_index_from_facing(int facing_angle);
    };
}

#endif