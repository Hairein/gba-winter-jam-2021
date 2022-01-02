#include "ingame.h"
#include "enemy_shot.h"

#include "enemy_shot_handler.h"

namespace mks
{
    EnemyShotHandler::EnemyShotHandler(Ingame* ingame_ptr)
    {
        this->ingame = ingame_ptr;
    }

    EnemyShotHandler::~EnemyShotHandler()
    {
    }
        
    void EnemyShotHandler::init()
    {
        for(int index = 0; index < DEFAULT_SPRITE_VECTOR_SIZE; index++)
        {
            EnemyShot new_shot(ingame);
            shots.push_back(new_shot);
        }
    }

    void EnemyShotHandler::shutdown()
    {
        shots.clear();
    }

    void EnemyShotHandler::update(bn::fixed_point calculated_map_center)
    {
        for(size_t index = 0; index < shots.size(); index++)
        {
            if(shots[index].is_active())
            {
                shots[index].update(calculated_map_center);
            }
        }
    }

    bool EnemyShotHandler::spawn(bn::fixed_point& map_position, bn::fixed& map_angle)
    {
        for(size_t index = 0; index < shots.size(); index++)
        {
            if(!shots[index].is_active())
            {
                shots[index].init(map_position, map_angle);
                
                return true;
            }
        }

        return false;
    }

}