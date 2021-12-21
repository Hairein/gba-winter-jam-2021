#ifndef MKS_POW_CAGE_H
#define MKS_POW_CAGE_H

#include <memory.h>

#include "bn_core.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"

#include "bn_sprite_items_pow_cage.h"

#include "globals.h"
#include "map_entity.h"
#include "vector_helper.h"

namespace mks
{
    class PowCage : public MapEntity
    {
    public: 
        PowCage(Ingame* ingame_ptr);
        ~PowCage();
        
        void init(bn::fixed_point& new_position, bn::fixed& new_angle);
        void shutdown();
        void update(bn::fixed_point calculated_map_center);

    protected:
        Ingame* ingame;
    };
}

#endif