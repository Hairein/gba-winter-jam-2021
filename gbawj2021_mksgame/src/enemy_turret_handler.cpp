#include "enemy_turret_handler.h"

namespace mks
{
    EnemyTurretHandler::EnemyTurretHandler()
    {
    }

    EnemyTurretHandler::~EnemyTurretHandler()
    {
    }
        
    void EnemyTurretHandler::init()
    {
        for(int index = 0; index < DEFAULT_SPRITE_VECTOR_SIZE; index++)
        {
            EnemyTurret new_enemy_turret;
            enemy_turrets.push_back(new_enemy_turret);
        }
    }

    void EnemyTurretHandler::shutdown()
    {
        enemy_turrets.clear();
    }

    void EnemyTurretHandler::update(std::unique_ptr<VectorHelper>& vector_helper, bn::fixed_point& map_center, bn::fixed& map_yaw)
    {
        for(size_t index = 0; index < enemy_turrets.size(); index++)
        {
            if(enemy_turrets[index].is_active())
            {
                enemy_turrets[index].update(vector_helper, map_center, map_yaw);
            }
        }
    }

    bool EnemyTurretHandler::spawn(bn::fixed_point& map_position, bn::fixed& map_angle)
    {
        for(size_t index = 0; index < enemy_turrets.size(); index++)
        {
            if(!enemy_turrets[index].is_active())
            {
                // Spawn both sprites at same position, angle
                enemy_turrets[index].init(map_position, map_angle);
                
                return true;
            }
        }

        return false;
    }

}