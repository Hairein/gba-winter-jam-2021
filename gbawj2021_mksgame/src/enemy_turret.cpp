#include "enemy_turret.h"

namespace mks
{
    EnemyTurret::EnemyTurret()
        : MultiMapEntity(2)
    {
    }

    EnemyTurret::~EnemyTurret()
    {
    }
        
    void EnemyTurret::init(bn::fixed_point& new_position, bn::fixed& new_angle)
    {        
        MultiMapEntity::init();

        positions[0] = new_position;
        angles[0] = new_angle;

        positions[1] = new_position;
        angles[1] = new_angle;

        initial_facing_angle = new_angle;
    }

    void EnemyTurret::shutdown()
    {
        MultiMapEntity::shutdown();
    }

    void EnemyTurret::update(VectorHelper& vector_helper, bn::fixed_point& map_center, bn::fixed& map_yaw)
    {
        MultiMapEntity::update();

        if(!is_active())
        {
            return;
        }

        // TODO Calculate turret gun rotation as needed

        bn::fixed_point new_sprite_position[2];
        bn::fixed new_sprite_rotation[2];
        vector_helper.calculate_sprite_position_angle(map_center, map_yaw, positions[0], angles[0], new_sprite_position[0], new_sprite_rotation[0]);
        vector_helper.calculate_sprite_position_angle(map_center, map_yaw, positions[1], angles[1], new_sprite_position[1], new_sprite_rotation[1]);

        set_sprite(0, bn::sprite_items::enemy_turret1_base.create_sprite_optional(new_sprite_position[0].x(), new_sprite_position[0].y(), 0));
        sprites[0].get()->set_z_order(4);
        sprites[0].get()->set_rotation_angle(new_sprite_rotation[0]);

        set_sprite(1, bn::sprite_items::enemy_turret1_gun.create_sprite_optional(new_sprite_position[1].x(), new_sprite_position[1].y(), 0));
        sprites[1].get()->set_z_order(3);
        sprites[1].get()->set_rotation_angle(new_sprite_rotation[1]);
    }
}