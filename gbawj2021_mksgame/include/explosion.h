#ifndef MKS_EXPLOSION_H
#define MKS_EXPLOSION_H

#include <memory.h>

#include "bn_core.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_vector.h"

#include "bn_sprite_items_explosion_sequence1.h"

#include "globals.h"
#include "map_entity.h"
#include "vector_helper.h"

namespace mks
{
    class Explosion : public MapEntity
    {
    public: 
        Explosion();
        ~Explosion();
        
        void init(bn::fixed_point& new_position, bn::fixed& new_angle);
        void shutdown();
        void update(std::unique_ptr<VectorHelper>& vector_helper, bn::fixed_point& map_center, bn::fixed& map_yaw);

    protected:
        int sprite_index;
        int frame_hold_counter;
    };
}

#endif