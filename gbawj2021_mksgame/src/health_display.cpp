#include "ingame.h"

#include "health_display.h"

namespace mks
{
    HealthDisplay::HealthDisplay(Ingame* ingame_ptr)
        : MultiUiElement(2)
    {
        ingame = ingame_ptr;
    }

    HealthDisplay::~HealthDisplay()
    {
    }

    void HealthDisplay::init()
    {   
        MultiUiElement::init();  

        last_health_value = -1; 
    }

    void HealthDisplay::shutdown()
    {
        MultiUiElement::shutdown();     
    }

    void HealthDisplay::update()
    {
        MultiUiElement::update(); 

        if(last_health_value != ingame->get_player_health())
        {
            set_sprite(0, bn::sprite_items::health_bar.create_sprite_optional(-70,-71));
            set_z_order(0, 1);

            bn::fixed pip_offset = bn::fixed(-85) + ((ingame->get_player_health() * bn::fixed(30)) / bn::fixed(100));
            bn::fixed_point new_point(pip_offset, -71);
            set_position(1, new_point);

            last_health_value = ingame->get_player_health();
        }
    }
}