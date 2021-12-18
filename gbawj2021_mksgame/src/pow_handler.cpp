#include "pow_handler.h"

namespace mks
{
    PowHandler::PowHandler()
    {
    }

    PowHandler::~PowHandler()
    {
    }
        
    void PowHandler::init()
    {
        for(int index = 0; index < DEFAULT_SPRITE_VECTOR_SIZE; index++)
        {
            Pow new_pow;
            pows.push_back(new_pow);
        }
    }

    void PowHandler::shutdown()
    {
        pows.clear();
    }

    void PowHandler::update(std::unique_ptr<VectorHelper>& vector_helper, bn::fixed_point& map_center, bn::fixed& map_yaw)
    {
        for(int index = 0; index < DEFAULT_SPRITE_VECTOR_SIZE; index++)
        {
            if(pows[index].is_active())
            {
                pows[index].update(vector_helper, map_center, map_yaw);
            }
        }
    }

    bool PowHandler::spawn(bn::fixed_point& map_position, bn::fixed& map_angle)
    {
        for(int index = 0; index < DEFAULT_SPRITE_VECTOR_SIZE; index++)
        {
            if(!pows[index].is_active())
            {
                pows[index].init(map_position, map_angle);
                
                return true;
            }
        }

        return false;
    }
}