#include "vector_helper.h"
#include "ingame.h"
#include "pow_cage.h"

#include "pow_cage_handler.h"

namespace mks
{
    PowCageHandler::PowCageHandler(Ingame* ingame_ptr)
    {
        ingame = ingame_ptr;
    }

    PowCageHandler::~PowCageHandler()
    {
    }
        
    void PowCageHandler::init()
    {
        for(int index = 0; index < DEFAULT_SPRITE_VECTOR_SIZE; index++)
        {
            PowCage new_pow_cage(ingame);
            pow_cages.push_back(new_pow_cage);
        }
    }

    void PowCageHandler::shutdown()
    {
        pow_cages.clear();
    }

    void PowCageHandler::update(bn::fixed_point calculated_map_center)
    {
        for(size_t index = 0; index < pow_cages.size(); index++)
        {
            if(pow_cages[index].is_active())
            {
                pow_cages[index].update(calculated_map_center);
            }
        }
    }

    bool PowCageHandler::spawn(bn::fixed_point& map_position, bn::fixed& map_angle)
    {
        for(size_t index = 0; index < pow_cages.size(); index++)
        {
            if(!pow_cages[index].is_active())
            {
                pow_cages[index].init(map_position, map_angle);
                
                return true;
            }
        }

        return false;
    }

    size_t PowCageHandler::count()
    {
        return pow_cages.size();
    }

    PowCage& PowCageHandler::get(size_t index)
    {
        return pow_cages[index];
    }

    void PowCageHandler::apply_damage(size_t index, bn::fixed damage)
    {
        pow_cages[index].take_damage(damage);
    }
}