#include "explosion_handler.h"

namespace mks
{
    ExplosionHandler::ExplosionHandler()
    {
    }

    ExplosionHandler::~ExplosionHandler()
    {
    }
        
    void ExplosionHandler::init()
    {
        for(int index = 0; index < DEFAULT_SPRITE_VECTOR_SIZE; index++)
        {
            Explosion new_explosion;
            explosions.push_back(new_explosion);
        }
    }

    void ExplosionHandler::shutdown()
    {
        explosions.clear();
    }

    void ExplosionHandler::update(std::unique_ptr<VectorHelper>& vector_helper, bn::fixed_point& map_center, bn::fixed& map_yaw)
    {
        for(int index = 0; index < DEFAULT_SPRITE_VECTOR_SIZE; index++)
        {
            if(explosions[index].is_active())
            {
                explosions[index].update(vector_helper, map_center, map_yaw);
            }
        }
    }

    bool ExplosionHandler::spawn_explosion(bn::fixed_point& map_position, bn::fixed& map_angle)
    {
        for(int index = 0; index < DEFAULT_SPRITE_VECTOR_SIZE; index++)
        {
            if(!explosions[index].is_active())
            {
                explosions[index].init(map_position, map_angle);
                
                return true;
            }
        }

        return false;
    }

}