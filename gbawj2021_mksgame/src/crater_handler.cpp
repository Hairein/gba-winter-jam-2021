#include "ingame.h"
#include "crater.h"

#include "crater_handler.h"

namespace mks
{
    CraterHandler::CraterHandler(Ingame* ingame_ptr)
    {
        this->ingame = ingame_ptr;
    }

    CraterHandler::~CraterHandler()
    {
    }
        
    void CraterHandler::init()
    {
        for(int index = 0; index < DEFAULT_SPRITE_VECTOR_SIZE; index++)
        {
            Crater new_crater(ingame);
            craters.push_back(new_crater);
        }
    }

    void CraterHandler::shutdown()
    {
        craters.clear();
    }

    void CraterHandler::update(bn::fixed_point calculated_map_center)
    {
        for(size_t index = 0; index < craters.size(); index++)
        {
            if(craters[index].is_active())
            {
                craters[index].update(calculated_map_center);
            }
        }
    }

    bool CraterHandler::spawn(bn::fixed_point& map_position)
    {
        for(size_t index = 0; index < craters.size(); index++)
         {
            if(!craters[index].is_active())
            {
                craters[index].init(map_position);
                
                return true;
            }
        }

        return false;
    }
}