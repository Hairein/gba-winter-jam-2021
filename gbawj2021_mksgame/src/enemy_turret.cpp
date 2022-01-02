#include "bn_log.h"
#include "bn_math.h"

#include "vector_helper.h"
#include "ingame.h"
#include "explosion_handler.h"
#include "crater_handler.h"
#include "enemy_shot_handler.h"

#include "enemy_turret.h"

namespace mks
{
    EnemyTurret::EnemyTurret(Ingame* ingame_ptr)
        : MultiMapEntity(2)
    {
        this->ingame = ingame_ptr;
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

        initial_angle = new_angle;
        current_angle = initial_angle;

        health = TURRET_MAX_HEALTH;

        last_shot = TURRET_SHOT_INTERVAL;
    }

    void EnemyTurret::shutdown()
    {
        MultiMapEntity::shutdown();
    }

    void EnemyTurret::update(bn::fixed_point calculated_map_center)
    {
        MultiMapEntity::update();

        if(!is_active())
        {
            return;
        }

        if(health <= bn::fixed(0))
        {
            ingame->get_explosion_handler()->spawn(positions[0], angles[0]);
            ingame->get_crater_handler()->spawn(positions[0]);

            shutdown();
            return;
        }

        auto can_shoot = false;
        auto angle_to_player = bn::fixed(0);

        // Calculate turret gun rotation as needed
        auto distance_to_player = ingame->get_vector_helper()->get_distance(ingame->get_map_center(), positions[0]);
        if(distance_to_player > ENEMY_SENSOR_RANGE)
        {
            current_angle += ENEMY_IDLE_ROTATE;
        }
        else
        {
            // Determine angle to player in relation
            angle_to_player = ingame->get_vector_helper()->get_angle(positions[0], ingame->get_map_center());
            auto diff_angle = angle_to_player - current_angle;
            auto abs_diff_angle = bn::abs(diff_angle);
                        
            if(diff_angle > bn::fixed(0) && abs_diff_angle <= 180)
            {
                current_angle -= ENEMY_IDLE_ROTATE;
            }
            else if(diff_angle > bn::fixed(0) && abs_diff_angle > 180)
            {
                current_angle += ENEMY_IDLE_ROTATE;
            }
            else if(diff_angle < bn::fixed(0)  && abs_diff_angle <= 180)
            {
                current_angle += ENEMY_IDLE_ROTATE;
            }       
            else if(diff_angle < bn::fixed(0)  && abs_diff_angle > 180)
            {
                current_angle -= ENEMY_IDLE_ROTATE;
            }   

            if(diff_angle < bn::fixed(2))
            {
                // Target in sights
                can_shoot = true;
            }
        }
        while(current_angle < bn::fixed(0)) current_angle += bn::fixed(360);
        while(current_angle >= bn::fixed(360)) current_angle -= bn::fixed(360);

        bn::fixed_point new_sprite_position[2];
        bn::fixed new_sprite_rotation[2];
        ingame->get_vector_helper()->calculate_sprite_position_angle(calculated_map_center, ingame->get_map_yaw(), positions[0], angles[0], new_sprite_position[0], new_sprite_rotation[0]);
        ingame->get_vector_helper()->calculate_sprite_position_angle(calculated_map_center, ingame->get_map_yaw(), positions[1], angles[1], new_sprite_position[1], new_sprite_rotation[1]);

        set_sprite(0, bn::sprite_items::enemy_turret1_base.create_sprite_optional(new_sprite_position[0].x(), new_sprite_position[0].y(), 0));
        sprites[0].get()->set_z_order(4);
        sprites[0].get()->set_rotation_angle(new_sprite_rotation[0]);

        set_sprite(1, bn::sprite_items::enemy_turret1_gun.create_sprite_optional(new_sprite_position[1].x(), new_sprite_position[1].y(), 0));
        sprites[1].get()->set_z_order(3);

        bn::fixed final_rotation = new_sprite_rotation[1] + current_angle;
        while(final_rotation >= bn::fixed(360)) final_rotation -= bn::fixed(360);
        sprites[1].get()->set_rotation_angle(final_rotation);

        // Handle shooting
        if(last_shot >= TURRET_SHOT_INTERVAL && can_shoot)
        {
            last_shot -= TURRET_SHOT_INTERVAL;
            
            BN_LOG("Turret shooting!");

            auto adapted_angle_to_player = final_rotation - bn::fixed(180);
            while(adapted_angle_to_player < bn::fixed(0)) final_rotation += bn::fixed(360);

            ingame->get_enemy_shot_handler()->spawn(positions[1], adapted_angle_to_player); 
        }
        else
        {
            if(last_shot < TURRET_SHOT_INTERVAL) last_shot++;
        }
    }

    void EnemyTurret::take_damage(bn::fixed damage)
    {
        health -= damage;
    }
}