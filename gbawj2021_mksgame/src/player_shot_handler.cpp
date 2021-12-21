#include "ingame.h"
#include "player_shot.h"

#include "player_shot_handler.h"

namespace mks
{
    PlayerShotHandler::PlayerShotHandler(Ingame* ingame_ptr)
    {
        this->ingame = ingame_ptr;
    }

    PlayerShotHandler::~PlayerShotHandler()
    {
    }
        
    void PlayerShotHandler::init()
    {
        for(int index = 0; index < DEFAULT_SPRITE_VECTOR_SIZE; index++)
        {
            PlayerShot new_shot(ingame);
            shots.push_back(new_shot);
        }
    }

    void PlayerShotHandler::shutdown()
    {
        shots.clear();
    }

    void PlayerShotHandler::update(bn::fixed_point calculated_map_center)
    {
        for(size_t index = 0; index < shots.size(); index++)
        {
            if(shots[index].is_active())
            {
                shots[index].update(calculated_map_center);
            }
        }
    }

    bool PlayerShotHandler::spawn(bn::fixed_point& map_position, bn::fixed& map_angle)
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