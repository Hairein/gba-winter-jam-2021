#ifndef MKS_CRATER_H
#define MKS_CRATER_H

#include "bn_core.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_random.h"

#include "bn_sprite_items_craters.h"

#include "globals.h"
#include "map_entity.h"
#include "vector_helper.h"

namespace mks
{
    class Crater : public MapEntity
    {
    public: 
        Crater();
        ~Crater();
        
        void init(bn::random& random, bn::fixed_point& new_position);
        void shutdown();
        void update(VectorHelper& vector_helper, bn::fixed_point& map_center, bn::fixed& map_yaw);
    };
}

#endif