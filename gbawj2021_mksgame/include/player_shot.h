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

namespace mks
{
    class Ingame;

    class PlayerShot : public MapEntity
    {
    public: 
        PlayerShot(Ingame* ingame_ptr);
        ~PlayerShot();
        
        void init(bn::fixed_point& new_position, bn::fixed& new_angle);
        void shutdown();
        void update(bn::fixed_point calculated_map_center);

    protected:
        Ingame* ingame;

        int sprite_index;
        int frame_hold_counter;
        
        int lifetime;

        bool handle_hit_checks();
        bool check_hit(bn::fixed_point target);
    };
}

#endif