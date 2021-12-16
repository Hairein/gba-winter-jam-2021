#include "enemy_tank.h"

namespace mks
{
    EnemyTank::EnemyTank()
    {
    }

    EnemyTank::~EnemyTank()
    {
    }
        
    void EnemyTank::init(bn::fixed_point& new_position, bn::fixed& new_angle)
    {        
        DualMapEntity::init();

        position[0] = new_position;
        angle[0] = new_angle;

        position[1] = new_position;
        angle[1] = new_angle;

        initial_facing_angle = new_angle;
    }

    void EnemyTank::shutdown()
    {
        DualMapEntity::shutdown();
    }

    void EnemyTank::update(VectorHelper& vector_helper, bn::fixed_point& map_center, bn::fixed& map_yaw)
    {
        DualMapEntity::update();

        if(!is_active())
        {
            return;
        }

        // TODO Calculate turret gun rotation as needed

        bn::fixed_point new_sprite_position[2];
        bn::fixed new_sprite_rotation[2];
        vector_helper.calculate_sprite_position_angle(map_center, map_yaw, position[0], angle[0], new_sprite_position[0], new_sprite_rotation[0]);
        vector_helper.calculate_sprite_position_angle(map_center, map_yaw, position[1], angle[1], new_sprite_position[1], new_sprite_rotation[1]);

        set_sprite(0, bn::sprite_items::enemy_tank_tracks.create_sprite_optional(new_sprite_position[0].x(), new_sprite_position[0].y(), 0));
        sprite[0].get()->set_z_order(4);
        sprite[0].get()->set_rotation_angle(new_sprite_rotation[0]);

        set_sprite(1, bn::sprite_items::enemy_tank_turret.create_sprite_optional(new_sprite_position[1].x(), new_sprite_position[1].y(), 0));
        sprite[1].get()->set_z_order(3);
        sprite[1].get()->set_rotation_angle(new_sprite_rotation[1]);
    }
}