#ifndef MKS_UI_ELEMENT_H
#define MKS_UI_ELEMENT_H

#include "bn_core.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"

#include "globals.h"

namespace mks
{
    class UiElement
    {
    public: 
        UiElement();
        ~UiElement();
        
        void init();
        void shutdown();
        void update();

        bool is_active();

        void set_sprite(bn::optional<bn::sprite_ptr> new_sprite);
        bn::optional<bn::sprite_ptr> get_sprite();

        void set_position(bn::fixed_point new_position);
        bn::fixed_point get_position();

        void set_angle(bn::fixed new_angle);
        bn::fixed get_angle();

        void set_z_order(int order);
        int get_z_order();
        
    protected:
        bool active;
        
        bn::optional<bn::sprite_ptr> sprite;
    };
}

#endif