#include "enemy_tank.h"
#include "vector_helper.h"

#include "enemy_tank_handler.h"

namespace mks
{
    EnemyTankHandler::EnemyTankHandler(Ingame* ingame_ptr)
    {
        ingame = ingame_ptr;
    }

    EnemyTankHandler::~EnemyTankHandler()
    {
    }
        
    void EnemyTankHandler::init()
    {
        for(int index = 0; index < DEFAULT_SPRITE_VECTOR_SIZE; index++)
        {
            EnemyTank new_enemy_turret(ingame);
            enemy_tanks.push_back(new_enemy_turret);
        }
    }

    void EnemyTankHandler::shutdown()
    {
        enemy_tanks.clear();
    }

    void EnemyTankHandler::update(bn::fixed_point calculated_map_center)
    {
        for(size_t index = 0; index < enemy_tanks.size(); index++)
        {
            if(enemy_tanks[index].is_active())
            {
                enemy_tanks[index].update(calculated_map_center);
            }
        }
    }

    bool EnemyTankHandler::spawn(bn::fixed_point& map_position, bn::fixed& map_angle)
    {
        for(size_t index = 0; index < enemy_tanks.size(); index++)
        {
            if(!enemy_tanks[index].is_active())
            {
                // Spawn both sprites at same position, angle
                enemy_tanks[index].init(map_position, map_angle);
                
                return true;
            }
        }

        return false;
    }

}