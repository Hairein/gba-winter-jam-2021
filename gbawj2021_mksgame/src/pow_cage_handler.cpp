#include "pow_cage_handler.h"

namespace mks
{
    PowCageHandler::PowCageHandler()
    {
    }

    PowCageHandler::~PowCageHandler()
    {
    }
        
    void PowCageHandler::init()
    {
        for(int index = 0; index < DEFAULT_SPRITE_VECTOR_SIZE; index++)
        {
            PowCage new_pow_cage;
            pow_cages.push_back(new_pow_cage);
        }
    }

    void PowCageHandler::shutdown()
    {
        pow_cages.clear();
    }

    void PowCageHandler::update(std::unique_ptr<VectorHelper>& vector_helper, bn::fixed_point& map_center, bn::fixed& map_yaw)
    {
        for(int index = 0; index < DEFAULT_SPRITE_VECTOR_SIZE; index++)
        {
            if(pow_cages[index].is_active())
            {
                pow_cages[index].update(vector_helper, map_center, map_yaw);
            }
        }
    }

    bool PowCageHandler::spawn_pow_cage(bn::fixed_point& map_position, bn::fixed& map_angle)
    {
        for(int index = 0; index < DEFAULT_SPRITE_VECTOR_SIZE; index++)
        {
            if(!pow_cages[index].is_active())
            {
                pow_cages[index].init(map_position, map_angle);
                
                return true;
            }
        }

        return false;
    }

}