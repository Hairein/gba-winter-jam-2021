#include "hit_handler.h"

namespace mks
{
    HitHandler::HitHandler()
    {
    }

    HitHandler::~HitHandler()
    {
    }
        
    void HitHandler::init()
    {
        for(int index = 0; index < DEFAULT_SPRITE_VECTOR_SIZE; index++)
        {
            Hit new_hit;
            hits.push_back(new_hit);
        }
    }

    void HitHandler::shutdown()
    {
        hits.clear();
    }

    void HitHandler::update(std::unique_ptr<VectorHelper>& vector_helper, bn::fixed_point& map_center, bn::fixed& map_yaw)
    {
        for(int index = 0; index < DEFAULT_SPRITE_VECTOR_SIZE; index++)
        {
            if(hits[index].is_active())
            {
                hits[index].update(vector_helper, map_center, map_yaw);
            }
        }
    }

    bool HitHandler::spawn(bn::fixed_point& map_position, bn::fixed& map_angle)
    {
        for(int index = 0; index < DEFAULT_SPRITE_VECTOR_SIZE; index++)
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