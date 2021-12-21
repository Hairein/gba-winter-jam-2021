#include "ingame.h"
#include "hit.h"
#include "vector_helper.h"

#include "hit_handler.h"

namespace mks
{
    HitHandler::HitHandler(Ingame* ingame_ptr)
    {
        this->ingame = ingame_ptr;
    }

    HitHandler::~HitHandler()
    {
    }
        
    void HitHandler::init()
    {
        for(int index = 0; index < DEFAULT_SPRITE_VECTOR_SIZE; index++)
        {
            Hit new_hit(ingame);
            hits.push_back(new_hit);
        }
    }

    void HitHandler::shutdown()
    {
        hits.clear();
    }

    void HitHandler::update(bn::fixed_point calculated_map_center)
    {
        for(size_t index = 0; index < hits.size(); index++)
        {
            if(hits[index].is_active())
            {
                hits[index].update(calculated_map_center);
            }
        }
    }

    bool HitHandler::spawn(bn::fixed_point& map_position, bn::fixed& map_angle)
    {
        for(size_t index = 0; index < hits.size(); index++)
        {
            if(!hits[index].is_active())
            {
                hits[index].init(map_position, map_angle);
                
                return true;
            }
        }

        return false;
    }

}