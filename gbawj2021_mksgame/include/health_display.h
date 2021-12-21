#ifndef MKS_HEALTH_DISPLAY_H
#define MKS_HEALTH_DISPLAY_H

#include "bn_core.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"

#include "bn_sprite_items_health_bar.h"
#include "bn_sprite_items_health_pip.h"

#include "globals.h"
#include "multi_ui_element.h"

namespace mks
{
    class Ingame;

    class HealthDisplay : public MultiUiElement
    {
    public: 
        HealthDisplay(Ingame* ingame_ptr);
        ~HealthDisplay();
        
        void init();
        void shutdown();
        void update();
    
    protected:
        Ingame* ingame;

        bn::fixed last_health_value;
    };
}

#endif