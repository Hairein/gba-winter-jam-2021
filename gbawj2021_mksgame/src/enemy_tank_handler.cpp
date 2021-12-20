#include "enemy_tank_handler.h"

namespace mks
{
    EnemyTankHandler::EnemyTankHandler()
    {
    }

    EnemyTankHandler::~EnemyTankHandler()
    {
    }
        
    void EnemyTankHandler::init()
    {
        for(int index = 0; index < DEFAULT_SPRITE_VECTOR_SIZE; index++)
        {
            EnemyTank new_enemy_turret;
            enemy_tanks.push_back(new_enemy_turret);
        }
    }

    void EnemyTankHandler::shutdown()
    {
        enemy_tanks.clear();
    }

    void EnemyTankHandler::update(std::unique_ptr<VectorHelper>& vector_helper, bn::fixed_point& map_center, bn::fixed& map_yaw)
    {
        for(size_t index = 0; index < enemy_tanks.size(); index++)
        {
            if(enemy_tanks[index].is_active())
            {
                enemy_tanks[index].update(vector_helper, map_center, map_yaw);
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