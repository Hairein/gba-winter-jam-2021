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

    void VectorHelper::calculate_sprite_position_angle(bn::fixed_point& map_center, bn::fixed& map_yaw, 
        bn::fixed_point& map_entity_position, bn::fixed& map_entity_angle, 
        bn::fixed_point& sprite_position, bn::fixed& sprite_angle)
    {
        auto unrotated_sprite_position = map_entity_position - map_center;       
        
        auto raw_rotation =  -map_yaw;
        while(raw_rotation < bn::fixed(0)) raw_rotation += bn::fixed(360);
        while(raw_rotation >= bn::fixed(360)) raw_rotation -= bn::fixed(360);

        sprite_position = rotate_vector(unrotated_sprite_position, raw_rotation);
        
        sprite_angle = map_yaw - map_entity_angle;
        while(sprite_angle < bn::fixed(0)) sprite_angle += bn::fixed(360);
        while(sprite_angle >= bn::fixed(360)) sprite_angle -= bn::fixed(360);
    }

    int VectorHelper::calculate_sprite_index_from_facing(int facing_angle)
    {
        // if(facing_angle <= 15 || facing_angle > 345)
        // {
        //     return 0;
        // }
        
        // auto new_facing_angle = facing_angle + 15;
        // while(new_facing_angle < 0) new_facing_angle += 360;
        // while(new_facing_angle >= 360) new_facing_angle -= 360;
        // return new_facing_angle / 30;
        
        auto new_facing_angle = facing_angle + 15;
        while(new_facing_angle < 0) new_facing_angle += 360;
        while(new_facing_angle >= 360) new_facing_angle -= 360;
        return new_facing_angle / 30;
    }
}