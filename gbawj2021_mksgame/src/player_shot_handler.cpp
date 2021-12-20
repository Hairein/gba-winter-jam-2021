#include "player_shot_handler.h"

namespace mks
{
    PlayerShotHandler::PlayerShotHandler()
    {
    }

    PlayerShotHandler::~PlayerShotHandler()
    {
    }
        
    void PlayerShotHandler::init()
    {
        for(int index = 0; index < DEFAULT_SPRITE_VECTOR_SIZE; index++)
        {
            PlayerShot new_shot;
            shots.push_back(new_shot);
        }
    }

    void PlayerShotHandler::shutdown()
    {
        shots.clear();
    }

    void PlayerShotHandler::update(std::unique_ptr<VectorHelper>& vector_helper, std::unique_ptr<HitHandler>& hit_handler, bn::fixed_point& map_center, bn::fixed& map_yaw)
    {
        for(size_t index = 0; index < shots.size(); index++)
        {
            if(shots[index].is_active())
            {
                shots[index].update(vector_helper, hit_handler, map_center, map_yaw);
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