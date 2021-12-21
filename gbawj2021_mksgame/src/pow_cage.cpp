#include "vector_helper.h"
#include "ingame.h"
#include "explosion_handler.h"
#include "crater_handler.h"
#include "pow_handler.h"

#include "pow_cage.h"

namespace mks
{
    PowCage::PowCage(Ingame* ingame_ptr)
    {
        ingame = ingame_ptr;
 
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

        health = POW_CAGE_MAX_HEALTH;
    }

    void PowCage::shutdown()
    {
        MapEntity::shutdown();
    }

    void PowCage::update(bn::fixed_point calculated_map_center)
    {
        MapEntity::update();

        if(!is_active())
        {
            return;
        }

        if(health <= bn::fixed(0))
        {
            ingame->get_explosion_handler()->spawn(position, angle);
            ingame->get_crater_handler()->spawn(position);
            bn::fixed zero_yaw{0};
            ingame->get_pow_handler()->spawn(position, zero_yaw);

            shutdown();
            return;
        }

        bn::fixed_point new_sprite_position;
        bn::fixed new_sprite_rotation;
        ingame->get_vector_helper()->calculate_sprite_position_angle(calculated_map_center, ingame->get_map_yaw(), position, angle, new_sprite_position, new_sprite_rotation);

        set_sprite(bn::sprite_items::pow_cage.create_sprite_optional(new_sprite_position.x(), new_sprite_position.y(), 0));
        sprite.get()->set_z_order(4);
        sprite.get()->set_rotation_angle(new_sprite_rotation);
    }

    void PowCage::take_damage(bn::fixed damage)
    {
        health -= damage;
    }
}