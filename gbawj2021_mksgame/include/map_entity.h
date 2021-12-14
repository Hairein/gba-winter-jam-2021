#ifndef MKS_MAP_ENTITY_H
#define MKS_MAP_ENTITY_H

#include "bn_core.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"

#include "globals.h"

namespace mks
{
    class MapEntity
    {
    public: 
        MapEntity();
        ~MapEntity();
        
        void init();
        void shutdown();
        void update();

        bool is_active();

        void set_sprite(bn::optional<bn::sprite_ptr> new_sprite);
        bn::optional<bn::sprite_ptr> get_sprite();

        void set_map_position(bn::fixed_point new_map_position);
        bn::fixed_point get_map_position();

        void set_map_angle(bn::fixed new_map_angle);
        bn::fixed get_map_angle();

        void set_z_order(int order);
        int get_z_order();

    protected:
        bool active;

        bn::fixed_point position;
        bn::fixed angle;
        
        bn::optional<bn::sprite_ptr> sprite;
    };
}

#endif