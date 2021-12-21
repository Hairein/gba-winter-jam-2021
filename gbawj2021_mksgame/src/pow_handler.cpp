#include "ingame.h"
#include "pow.h"
#include "vector_helper.h"

#include "pow_handler.h"

namespace mks
{
    PowHandler::PowHandler(Ingame* ingame_ptr)
    {
        ingame = ingame_ptr;
    }

    PowHandler::~PowHandler()
    {
    }
        
    void PowHandler::init()
    {
        for(int index = 0; index < DEFAULT_SPRITE_VECTOR_SIZE; index++)
        {
            Pow new_pow(ingame);
            pows.push_back(new_pow);
        }
    }

    void PowHandler::shutdown()
    {
        pows.clear();
    }

    void PowHandler::update(bn::fixed_point calculated_map_center)
    {
        for(size_t index = 0; index < pows.size(); index++)
        {
            if(pows[index].is_active())
            {
                pows[index].update(calculated_map_center);
            }
        }
    }

    bool PowHandler::spawn(bn::fixed_point& map_position, bn::fixed& map_angle)
    {
        for(size_t index = 0; index < pows.size(); index++)
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