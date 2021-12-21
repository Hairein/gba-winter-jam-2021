#include "ingame.h"
#include "vector_helper.h"
#include "explosion_handler.h"
#include "crater_handler.h"

#include "enemy_helicopter.h"

namespace mks
{
    EnemyHelicopter::EnemyHelicopter(Ingame* ingame_ptr)
    {
        this->ingame = ingame_ptr;

        active = false;
    }

    EnemyHelicopter::~EnemyHelicopter()
    {
    }
        
    void EnemyHelicopter::init(bn::fixed_point& new_position, bn::fixed& new_angle)
    {        
        MapEntity::init();

        position = new_position;
        angle = new_angle;

        initial_facing_angle = new_angle;

        health = HELICOPTER_MAX_HEALTH;
    }

    void EnemyHelicopter::shutdown()
    {
        MapEntity::shutdown();
    }

    void EnemyHelicopter::update(bn::fixed_point calculated_map_center)
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

            shutdown();
            return;
        }

        int sprite_index = 7; 

        bn::fixed_point new_sprite_position;
        bn::fixed new_sprite_rotation;
        ingame->get_vector_helper()->calculate_sprite_position_angle(calculated_map_center, ingame->get_map_yaw(), position, angle, new_sprite_position, new_sprite_rotation);

        set_sprite(bn::sprite_items::enemy_heli.create_sprite_optional(new_sprite_position.x(), new_sprite_position.y(), sprite_index));
        sprite.get()->set_z_order(4);
        sprite.get()->set_rotation_angle(new_sprite_rotation);
    }

    void EnemyHelicopter::take_damage(bn::fixed damage)
    {
        health -= damage;
    }
}