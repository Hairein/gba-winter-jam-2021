#include "ingame.h"

#include "pow.h"

namespace mks
{
    Pow::Pow(Ingame* ingame_ptr)
    {
        ingame = ingame_ptr;

        active = false;
    }

    Pow::~Pow()
    {
    }
        
    void Pow::init(bn::fixed_point& new_position, bn::fixed& new_angle)
    {        
        MapEntity::init();

        position = new_position;
        angle = new_angle;

        animate_counter = 0;
    }

    void Pow::shutdown()
    {
        MapEntity::shutdown();
    }

    void Pow::update(bn::fixed_point calculated_map_center)
    {
        MapEntity::update();

        if(!is_active())
        {
            return;
        }

        // TODO Check player helicopter pick-up to despawn
        // ingame->decrement_pows_left();

        bn::fixed_point new_sprite_position;
        bn::fixed new_sprite_rotation;
        ingame->get_vector_helper()->calculate_sprite_position_angle(calculated_map_center, ingame->get_map_yaw(), position, angle, new_sprite_position, new_sprite_rotation);

        set_sprite(bn::sprite_items::pow.create_sprite_optional(new_sprite_position.x(), new_sprite_position.y(), (animate_counter / 9) % MAX_POW_WAVE_INDEX));
        sprite.get()->set_z_order(3);
        sprite.get()->set_rotation_angle(0);

        animate_counter++;
    }
}