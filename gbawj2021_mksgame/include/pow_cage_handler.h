#ifndef MKS_POW_CAGE_HANDLER_H
#define MKS_POW_CAGE_HANDLER_H

#include "bn_core.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_vector.h"

#include "globals.h"
#include "pow_cage.h"
#include "vector_helper.h"

namespace mks
{
    class PowCageHandler
    {
    public: 
        PowCageHandler();
        ~PowCageHandler();
        
        void init();
        void shutdown();
        void update(VectorHelper& vector_helper, bn::fixed_point& map_center, bn::fixed& map_yaw);
       
        bool spawn_pow_cage(bn::fixed_point map_position, bn::fixed map_angle);

    protected:
        bn::vector<PowCage,DEFAULT_SPRITE_VECTOR_SIZE> pow_cages;
    };
}

#endif