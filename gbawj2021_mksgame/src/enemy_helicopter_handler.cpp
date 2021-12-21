#include "ingame.h"
#include "enemy_helicopter.h"
#include "vector_helper.h"

#include "enemy_helicopter_handler.h"

namespace mks
{
    EnemyHelicopterHandler::EnemyHelicopterHandler(Ingame* ingame_ptr)
    {
        this->ingame = ingame_ptr;
    }

    EnemyHelicopterHandler::~EnemyHelicopterHandler()
    {
    }
        
    void EnemyHelicopterHandler::init()
    {
        for(int index = 0; index < DEFAULT_SPRITE_VECTOR_SIZE; index++)
        {
            EnemyHelicopter new_enemy_heli(ingame);
            enemy_helis.push_back(new_enemy_heli);
        }
    }

    void EnemyHelicopterHandler::shutdown()
    {
        enemy_helis.clear();
    }

    void EnemyHelicopterHandler::update(bn::fixed_point calculated_map_center)
    {
        for(size_t index = 0; index < enemy_helis.size(); index++)
         {
            if(enemy_helis[index].is_active())
            {
                enemy_helis[index].update(calculated_map_center);
            }
        }
    }

    bool EnemyHelicopterHandler::spawn(bn::fixed_point& map_position, bn::fixed& map_angle)
    {
        for(size_t index = 0; index < enemy_helis.size(); index++)
        {
            if(!enemy_helis[index].is_active())
            {
                enemy_helis[index].init(map_position, map_angle);
                
                return true;
            }
        }

        return false;
    }

    size_t EnemyHelicopterHandler::count()
    {
        return enemy_helis.size();
    }

    EnemyHelicopter& EnemyHelicopterHandler::get(size_t index)
    {
        return enemy_helis[index];
    }

    void EnemyHelicopterHandler::apply_damage(size_t index, bn::fixed damage)
    {
        enemy_helis[index].take_damage(damage);
    }
}