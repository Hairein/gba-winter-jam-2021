#include "vector_helper.h"
#include "ingame.h"

#include "crater.h"

namespace mks
{
    Crater::Crater(Ingame* ingame_ptr)
    {
        ingame = ingame_ptr;
 
        active = false;
    }

    Crater::~Crater()
    {
    }
        
    void Crater::init(bn::fixed_point& new_position)
    {        
        MapEntity::init();

        position = new_position;
        angle = ingame->get_random()->get_fixed(bn::fixed(0), bn::fixed(360));

        int sprite_index = ingame->get_random()->get_int(0, MAX_CRATER_INDEX);

        set_sprite(bn::sprite_items::craters.create_sprite_optional(0, 0, sprite_index));
        sprite.get()->set_z_order(4);
    }

    void Crater::shutdown()
    {
        MapEntity::shutdown();
    }

    void Crater::update(bn::fixed_point calculated_map_center)
    {
        MapEntity::update();

        if(!is_active())
        {
            return;
        }

        bn::fixed_point new_sprite_position;
        bn::fixed new_sprite_rotation;
        ingame->get_vector_helper()->calculate_sprite_position_angle(calculated_map_center, ingame->get_map_yaw(), position, angle, new_sprite_position, new_sprite_rotation);

        sprite.get()->set_position(new_sprite_position);
        sprite.get()->set_rotation_angle(new_sprite_rotation);
    }
}