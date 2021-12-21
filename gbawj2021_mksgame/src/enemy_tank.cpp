#include "vector_helper.h"
#include "ingame.h"

#include "enemy_tank.h"

namespace mks
{
    EnemyTank::EnemyTank(Ingame* ingame_ptr)
        : MultiMapEntity(2)
    {
        ingame = ingame_ptr;
    }

    EnemyTank::~EnemyTank()
    {
    }
        
    void EnemyTank::init(bn::fixed_point& new_position, bn::fixed& new_angle)
    {        
        MultiMapEntity::init();

        positions[0] = new_position;
        angles[0] = new_angle;

        positions[1] = new_position;
        angles[1] = new_angle;

        initial_facing_angle = new_angle;
    }

    void EnemyTank::shutdown()
    {
        MultiMapEntity::shutdown();
    }

    void EnemyTank::update(bn::fixed_point calculated_map_center)
    {
        MultiMapEntity::update();

        if(!is_active())
        {
            return;
        }

        // TODO Calculate turret gun rotation as needed

        bn::fixed_point new_sprite_position[2];
        bn::fixed new_sprite_rotation[2];
        ingame->get_vector_helper()->calculate_sprite_position_angle(calculated_map_center, ingame->get_map_yaw(), positions[0], angles[0], new_sprite_position[0], new_sprite_rotation[0]);
        ingame->get_vector_helper()->calculate_sprite_position_angle(calculated_map_center, ingame->get_map_yaw(), positions[1], angles[1], new_sprite_position[1], new_sprite_rotation[1]);

        set_sprite(0, bn::sprite_items::enemy_tank_tracks.create_sprite_optional(new_sprite_position[0].x(), new_sprite_position[0].y(), 0));
        sprites[0].get()->set_z_order(4);
        sprites[0].get()->set_rotation_angle(new_sprite_rotation[0]);

        set_sprite(1, bn::sprite_items::enemy_tank_turret.create_sprite_optional(new_sprite_position[1].x(), new_sprite_position[1].y(), 0));
        sprites[1].get()->set_z_order(3);
        sprites[1].get()->set_rotation_angle(new_sprite_rotation[1]);
    }
}