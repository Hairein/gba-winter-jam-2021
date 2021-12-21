#include "vector_helper.h"
#include "ingame.h"
#include "hit_handler.h"
#include "enemy_turret_handler.h"
#include "enemy_turret.h"
#include "enemy_tank_handler.h"
#include "enemy_tank.h"
#include "enemy_helicopter_handler.h"
#include "enemy_helicopter.h"
#include "pow_cage_handler.h"
#include "pow_cage.h"

#include "player_shot.h"

namespace mks
{
    PlayerShot::PlayerShot(Ingame* ingame_ptr)
    {
        this->ingame = ingame_ptr;
    }

    PlayerShot::~PlayerShot()
    {
    }
        
    void PlayerShot::init(bn::fixed_point& new_position, bn::fixed& new_angle)
    {
        MapEntity::init();

        sprite_index = 0;
        frame_hold_counter = 0;

        position = new_position;
        angle = new_angle;

        lifetime = SHOT_LIFETIME;
    }

    void PlayerShot::shutdown()
    {
        MapEntity::shutdown();
    }

    void PlayerShot::update(bn::fixed_point calculated_map_center)
    {
        MapEntity::update();

        if(!is_active())
        {
            return;
        }

        if(lifetime <= 0)
        {
            ingame->get_hit_handler()->spawn(position, angle);
            
            shutdown();
            return;
        }

        if(handle_hit_checks())
        {
            ingame->get_hit_handler()->spawn(position, angle);

            shutdown();
            return;
        }

        if(sprite_index >= SHOT_SEQUENCE_MAX)
        {
            sprite_index -= SHOT_SEQUENCE_MAX;
        }

        bn::fixed_point new_sprite_position;
        bn::fixed new_sprite_rotation;
        ingame->get_vector_helper()->calculate_sprite_position_angle(calculated_map_center, ingame->get_map_yaw(), position, angle, new_sprite_position, new_sprite_rotation);

        if(frame_hold_counter >= SHORT_FRAME_HOLD)
        {
            set_sprite(bn::sprite_items::shot_blue.create_sprite_optional(new_sprite_position.x(),new_sprite_position.y(),sprite_index));
            sprite.get()->set_z_order(2);
            sprite.get()->set_rotation_angle(new_sprite_rotation);

            sprite_index++;
            frame_hold_counter = 0;
        }
        else
        {
            sprite.get()->set_position(new_sprite_position);
            sprite.get()->set_rotation_angle(new_sprite_rotation);
            
            frame_hold_counter++;
        }

        lifetime--;

        bn::fixed_point direction = ingame->get_vector_helper()->get_rotated_unit_vector_y(angle.floor_integer());
        direction *= bn::fixed(SHOT_VELOCITY);
        position += direction;
    }

    bool PlayerShot::handle_hit_checks()
    {
        for(size_t index = 0; index < ingame->get_enemy_turret_handler()->count(); index++)
        {
            auto turret = ingame->get_enemy_turret_handler()->get(index);
            if(!turret.is_active())
            {
                continue;
            }

            if(check_hit(turret.get_map_position(0)))
            {              
                ingame->get_enemy_turret_handler()->apply_damage(index, PLAYER_SHOT_DAMAGE);
                return true; 
            }
        }

        for(size_t index = 0; index < ingame->get_enemy_tank_handler()->count(); index++)
        {
            auto tank = ingame->get_enemy_tank_handler()->get(index);
            if(!tank.is_active())
            {
                continue;
            }

            if(check_hit(tank.get_map_position(0)))
            {
                
                ingame->get_enemy_tank_handler()->apply_damage(index, PLAYER_SHOT_DAMAGE);
                return true; 
            }
        }

        for(size_t index = 0; index < ingame->get_enemy_helicopter_handler()->count(); index++)
        {
            auto helicopter = ingame->get_enemy_helicopter_handler()->get(index);
            if(!helicopter.is_active())
            {
                continue;
            }

            if(check_hit(helicopter.get_map_position()))
            {
                
                ingame->get_enemy_helicopter_handler()->apply_damage(index, PLAYER_SHOT_DAMAGE);
                return true; 
            }
        }

        for(size_t index = 0; index < ingame->get_pow_cage_handler()->count(); index++)
        {
            auto pow_cage = ingame->get_pow_cage_handler()->get(index);
            if(!pow_cage.is_active())
            {
                continue;
            }

            if(check_hit(pow_cage.get_map_position()))
            {
                
                ingame->get_pow_cage_handler()->apply_damage(index, PLAYER_SHOT_DAMAGE);
                return true; 
            }
        }

        return false;
    }   

    bool PlayerShot::check_hit(bn::fixed_point target)
    {
        auto distance = ingame->get_vector_helper()->get_distance(target, position);
        if(distance <= PLAYER_SHOT_DAMAGE_RADIUS)
        {
            return true;
        }

        return false;
    }
}