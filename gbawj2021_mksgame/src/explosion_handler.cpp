#include "explosion.h"
#include "vector_helper.h"

#include "explosion_handler.h"

namespace mks
{
    ExplosionHandler::ExplosionHandler(Ingame* ingame_ptr)
    {
        this->ingame = ingame_ptr;
    }

    ExplosionHandler::~ExplosionHandler()
    {
    }
        
    void ExplosionHandler::init()
    {
        for(int index = 0; index < DEFAULT_SPRITE_VECTOR_SIZE; index++)
        {
            Explosion new_explosion(ingame);
            explosions.push_back(new_explosion);
        }
    }

    void ExplosionHandler::shutdown()
    {
        explosions.clear();
    }

    void ExplosionHandler::update(bn::fixed_point calculated_map_center)
    {
        for(size_t index = 0; index < explosions.size(); index++)
        {
            if(explosions[index].is_active())
            {
                explosions[index].update(calculated_map_center);
            }
        }
    }

    bool ExplosionHandler::spawn(bn::fixed_point& map_position, bn::fixed& map_angle)
    {
        for(size_t index = 0; index < explosions.size(); index++)
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