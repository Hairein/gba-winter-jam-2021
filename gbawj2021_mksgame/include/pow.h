#ifndef MKS_POW_H
#define MKS_POW_H

#include <memory.h>

#include "bn_core.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"

#include "bn_sprite_items_pow.h"

#include "globals.h"
#include "map_entity.h"
#include "vector_helper.h"

namespace mks
{
    class Ingame;

    class Pow : public MapEntity
    {
    public: 
        Pow(Ingame* ingame_ptr);
        ~Pow();
        
        void init(bn::fixed_point& new_position, bn::fixed& new_angle);
        void shutdown();
        void update(bn::fixed_point calculated_map_center);

    protected:
        Ingame* ingame;

        int animate_counter;
    };
}

#endif