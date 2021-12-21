#ifndef MKS_POW_CAGE_HANDLER_H
#define MKS_POW_CAGE_HANDLER_H

#include <vector>

#include "bn_core.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_vector.h"

#include "globals.h"

namespace mks
{
    class Ingame;
    class PowCage;

    class PowCageHandler
    {
    public: 
        PowCageHandler(Ingame* ingame_ptr);
        ~PowCageHandler();
        
        void init();
        void shutdown();
        void update(bn::fixed_point calculated_map_center);
       
        bool spawn(bn::fixed_point& map_position, bn::fixed& map_angle);

        size_t count();
        PowCage& get(size_t index);
        void apply_damage(size_t index, bn::fixed damage);

    protected:
        Ingame* ingame;

        std::vector<PowCage> pow_cages;
    };
}

#endif