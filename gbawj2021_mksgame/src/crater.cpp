#include "crater.h"

namespace mks
{
    Crater::Crater()
    {
        active = false;
    }

    Crater::~Crater()
    {
    }
        
    void Crater::init(std::unique_ptr<bn::random>& random, bn::fixed_point& new_position)
    {        
        MapEntity::init();

        position = new_position;
        angle = random.get()->get_fixed(bn::fixed(0), bn::fixed(360));

        int sprite_index = random.get()->get_int(0, MAX_CRATER_INDEX);

        set_sprite(bn::sprite_items::craters.create_sprite_optional(0, 0, sprite_index));
        sprite.get()->set_z_order(4);
    }

    void Crater::shutdown()
    {
        MapEntity::shutdown();
    }

    void Crater::update(std::unique_ptr<VectorHelper>& vector_helper, bn::fixed_point& map_center, bn::fixed& map_yaw)
    {
        MapEntity::update();

        if(!is_active())
        {
            return;
        }

        bn::fixed_point new_sprite_position;
        bn::fixed new_sprite_rotation;
        vector_helper.get()->calculate_sprite_position_angle(map_center, map_yaw, position, angle, new_sprite_position, new_sprite_rotation);

        sprite.get()->set_position(new_sprite_position);
        sprite.get()->set_rotation_angle(new_sprite_rotation);
    }
}