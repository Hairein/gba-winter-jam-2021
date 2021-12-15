#include "enemy_helicopter.h"

namespace mks
{
    EnemyHelicopter::EnemyHelicopter()
    {
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
    }

    void EnemyHelicopter::shutdown()
    {
        MapEntity::shutdown();
    }

    void EnemyHelicopter::update(VectorHelper& vector_helper, bn::fixed_point& map_center, bn::fixed& map_yaw)
    {
        MapEntity::update();

        if(!is_active())
        {
            return;
        }

        int sprite_index = 7; 

        bn::fixed_point new_sprite_position;
        bn::fixed new_sprite_rotation;
        vector_helper.calculate_sprite_position_angle(map_center, map_yaw, position, angle, new_sprite_position, new_sprite_rotation);

        set_sprite(bn::sprite_items::enemy_heli.create_sprite_optional(new_sprite_position.x(), new_sprite_position.y(), sprite_index));
        sprite.get()->set_z_order(4);
        sprite.get()->set_rotation_angle(new_sprite_rotation);
    }
}