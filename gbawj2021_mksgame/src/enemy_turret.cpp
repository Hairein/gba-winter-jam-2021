#include "enemy_turret.h"

namespace mks
{
    EnemyTurret::EnemyTurret()
    {
    }

    EnemyTurret::~EnemyTurret()
    {
    }
        
    void EnemyTurret::init(bn::fixed_point& new_position, bn::fixed& new_angle,
            int facing_angle)
    {        
        DualMapEntity::init();

        position[0] = new_position;
        angle[0] = new_angle;

        position[1] = new_position;
        angle[1] = new_angle;

        initial_facing_angle = facing_angle;
    }

    void EnemyTurret::shutdown()
    {
        DualMapEntity::shutdown();
    }

    void EnemyTurret::update(VectorHelper& vector_helper, bn::fixed_point& map_center, bn::fixed& map_yaw)
    {
        DualMapEntity::update();

        if(!is_active())
        {
            return;
        }

        int sprite_index = vector_helper.calculate_sprite_index_from_facing(initial_facing_angle);

        bn::fixed_point new_sprite_position[2];
        bn::fixed new_sprite_rotation[2];
        vector_helper.calculate_sprite_position_angle(map_center, map_yaw, position[0], angle[0], new_sprite_position[0], new_sprite_rotation[0]);
        vector_helper.calculate_sprite_position_angle(map_center, map_yaw, position[1], angle[1], new_sprite_position[1], new_sprite_rotation[1]);

        set_sprite(0, bn::sprite_items::turret_base_rotations.create_sprite_optional(new_sprite_position[0].x(), new_sprite_position[0].y(), sprite_index));
        sprite[0].get()->set_z_order(4);
        sprite[0].get()->set_rotation_angle(new_sprite_rotation[0]);

        set_sprite(1, bn::sprite_items::turret_gun_rotations.create_sprite_optional(new_sprite_position[1].x(), new_sprite_position[1].y(), sprite_index));
        sprite[1].get()->set_z_order(3);
        sprite[1].get()->set_rotation_angle(new_sprite_rotation[1]);
    }
}