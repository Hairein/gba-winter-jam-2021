#ifndef MKS_MULTI_MAP_ENTITY_H
#define MKS_MULTI_MAP_ENTITY_H

#include "bn_core.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_vector.h"

#include "globals.h"

namespace mks
{
    class MultiMapEntity
    {
    public: 
        MultiMapEntity(size_t size);
        ~MultiMapEntity();
        
        void init();
        void shutdown();
        void update();

        bool is_active();

        void set_sprite(int index, bn::optional<bn::sprite_ptr> new_sprite);
        bn::optional<bn::sprite_ptr> get_sprite(int index);

        void set_map_position(int index, bn::fixed_point& new_map_position);
        bn::fixed_point get_map_position(int index);

        void set_map_angle(int index, bn::fixed& new_map_angle);
        bn::fixed get_map_angle(int index);

        void set_z_order(int index, int order);
        int get_z_order(int index);

    protected:
        bool active;

        bn::vector<bn::fixed_point,DEFAULT_SPRITE_VECTOR_SIZE> positions;
        bn::vector<bn::fixed,DEFAULT_SPRITE_VECTOR_SIZE> angles;
        
        bn::vector<bn::optional<bn::sprite_ptr>,DEFAULT_SPRITE_VECTOR_SIZE> sprites;
    };
}

#endif