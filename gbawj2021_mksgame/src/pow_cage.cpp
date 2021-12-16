#include "pow_cage.h"

namespace mks
{
    PowCage::PowCage()
    {
        active = false;
    }

    PowCage::~PowCage()
    {
    }
        
    void PowCage::init(bn::fixed_point& new_position, bn::fixed& new_angle)
    {        
        MapEntity::init();

        position = new_position;
        angle = new_angle;
    }

    void PowCage::shutdown()
    {
        MapEntity::shutdown();
    }

    void PowCage::update(VectorHelper& vector_helper, bn::fixed_point& map_center, bn::fixed& map_yaw)
    {
        MapEntity::update();

        if(!is_active())
        {
            return;
        }

        bn::fixed_point new_sprite_position;
        bn::fixed new_sprite_rotation;
        vector_helper.calculate_sprite_position_angle(map_center, map_yaw, position, angle, new_sprite_position, new_sprite_rotation);

        set_sprite(bn::sprite_items::pow_cage.create_sprite_optional(new_sprite_position.x(), new_sprite_position.y(), 0));
        sprite.get()->set_z_order(4);
        sprite.get()->set_rotation_angle(new_sprite_rotation);
    }
}