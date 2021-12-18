#include "crater_handler.h"

namespace mks
{
    CraterHandler::CraterHandler()
    {
    }

    CraterHandler::~CraterHandler()
    {
    }
        
    void CraterHandler::init()
    {
        for(int index = 0; index < DEFAULT_SPRITE_VECTOR_SIZE; index++)
        {
            Crater new_crater;
            craters.push_back(new_crater);
        }
    }

    void CraterHandler::shutdown()
    {
        craters.clear();
    }

    void CraterHandler::update(VectorHelper& vector_helper, bn::fixed_point& map_center, bn::fixed& map_yaw)
    {
        for(int index = 0; index < DEFAULT_SPRITE_VECTOR_SIZE; index++)
        {
            if(craters[index].is_active())
            {
                craters[index].update(vector_helper, map_center, map_yaw);
            }
        }
    }

    bool CraterHandler::spawn(bn::random& random, bn::fixed_point& map_position)
    {
        for(int index = 0; index < DEFAULT_SPRITE_VECTOR_SIZE; index++)
        {
            if(!craters[index].is_active())
            {
                craters[index].init(random, map_position);
                
                return true;
            }
        }

        return false;
    }
}