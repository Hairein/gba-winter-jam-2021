#ifndef MKS_PLAYER_SHOT_H
#define MKS_PLAYER_SHOT_H

#include <memory.h>

#include "bn_core.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_vector.h"

#include "bn_sprite_items_shot_blue.h"

#include "globals.h"
#include "map_entity.h"
#include "vector_helper.h"
#include "hit_handler.h"

namespace mks
{
    class PlayerShot : public MapEntity
    {
    public: 
        PlayerShot();
        ~PlayerShot();
        
        void init(bn::fixed_point& new_position, bn::fixed& new_angle);
        void shutdown();
        void update(std::unique_ptr<VectorHelper>& vector_helper, std::unique_ptr<HitHandler>& hit_handler, bn::fixed_point& map_center, bn::fixed& map_yaw);

    protected:
        int sprite_index;
        int frame_hold_counter;
        
        int lifetime;
    };
}

#endif