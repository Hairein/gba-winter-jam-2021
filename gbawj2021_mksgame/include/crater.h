#ifndef MKS_CRATER_H
#define MKS_CRATER_H

#include <memory.h>

#include "bn_core.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_random.h"

#include "bn_sprite_items_craters.h"

#include "globals.h"
#include "map_entity.h"

namespace mks
{
    class Ingame;
    
    class Crater : public MapEntity
    {
    public: 
        Crater(Ingame* ingame_ptr);
        ~Crater();
        
        void init(bn::fixed_point& new_position);
        void shutdown();
        void update(bn::fixed_point calculated_map_center);

    protected:
        Ingame* ingame;
    };
}

#endif