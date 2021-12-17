#include "health_display.h"

namespace mks
{
    HealthDisplay::HealthDisplay()
        : MultiUiElement(2)
    {
    }

    HealthDisplay::~HealthDisplay()
    {
    }

    void HealthDisplay::init(bn::fixed& player_health)
    {   
        MultiUiElement::init();  

        set_sprite(0, bn::sprite_items::health_bar.create_sprite_optional(-70,-71));
        set_z_order(0, 1);

        bn::fixed pip_offset = bn::fixed(-85) + ((player_health * bn::fixed(30)) / bn::fixed(100));

        set_sprite(1, bn::sprite_items::health_pip.create_sprite_optional(pip_offset,-71));
        set_z_order(1, 0);

        last_health_value = player_health; 
    }

    void HealthDisplay::shutdown()
    {
        MultiUiElement::shutdown();     
    }

    void HealthDisplay::update(bn::fixed& player_health)
    {
        MultiUiElement::update(); 

        if(last_health_value != player_health)
        {
            bn::fixed pip_offset = bn::fixed(-85) + ((player_health * bn::fixed(30)) / bn::fixed(100));
            set_position(1, bn::fixed_point(pip_offset, -71));

            last_health_value = player_health;
        }
    }
}