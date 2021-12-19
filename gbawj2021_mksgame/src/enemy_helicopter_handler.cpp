#include "enemy_helicopter_handler.h"

namespace mks
{
    EnemyHelicopterHandler::EnemyHelicopterHandler()
    {
    }

    EnemyHelicopterHandler::~EnemyHelicopterHandler()
    {
    }
        
    void EnemyHelicopterHandler::init()
    {
        for(int index = 0; index < DEFAULT_SPRITE_VECTOR_SIZE; index++)
        {
            EnemyHelicopter new_enemy_heli;
            enemy_helis.push_back(new_enemy_heli);
        }
    }

    void EnemyHelicopterHandler::shutdown()
    {
        enemy_helis.clear();
    }

    void EnemyHelicopterHandler::update(std::unique_ptr<VectorHelper>& vector_helper, bn::fixed_point& map_center, bn::fixed& map_yaw)
    {
        for(int index = 0; index < DEFAULT_SPRITE_VECTOR_SIZE; index++)
        {
            if(enemy_helis[index].is_active())
            {
                enemy_helis[index].update(vector_helper, map_center, map_yaw);
            }
        }
    }

    bool EnemyHelicopterHandler::spawn(bn::fixed_point& map_position, bn::fixed& map_angle)
    {
        for(int index = 0; index < DEFAULT_SPRITE_VECTOR_SIZE; index++)
        {
            if(!enemy_helis[index].is_active())
            {
                enemy_helis[index].init(map_position, map_angle);
                
                return true;
            }
        }

        return false;
    }

}