#include "vector_helper.h"
#include "ingame.h"
#include "enemy_turret.h"

#include "enemy_turret_handler.h"

namespace mks
{
    EnemyTurretHandler::EnemyTurretHandler(Ingame* ingame_ptr)
    {
        this->ingame = ingame_ptr;
    }

    EnemyTurretHandler::~EnemyTurretHandler()
    {
    }
        
    void EnemyTurretHandler::init()
    {
        for(int index = 0; index < DEFAULT_SPRITE_VECTOR_SIZE; index++)
        {
            EnemyTurret new_enemy_turret(ingame);
            enemy_turrets.push_back(new_enemy_turret);
        }
    }

    void EnemyTurretHandler::shutdown()
    {
        enemy_turrets.clear();
    }

    void EnemyTurretHandler::update(bn::fixed_point calculated_map_center)
    {
        for(size_t index = 0; index < enemy_turrets.size(); index++)
        {
            if(enemy_turrets[index].is_active())
            {
                enemy_turrets[index].update(calculated_map_center);
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

    size_t EnemyTurretHandler::count()
    {
        return enemy_turrets.size();
    }

    EnemyTurret& EnemyTurretHandler::get(size_t index)
    {
        return enemy_turrets[index];
    }

    void EnemyTurretHandler::apply_damage(size_t index, bn::fixed damage)
    {
        enemy_turrets[index].take_damage(damage);
    }
}