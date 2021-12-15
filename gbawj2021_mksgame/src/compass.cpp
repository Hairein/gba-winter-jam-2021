#include "compass.h"

namespace mks
{
    Compass::Compass()
    {
    }

    Compass::~Compass()
    {
    }

    void Compass::init()
    {   
        UiElement::init();    
    }

    void Compass::shutdown()
    {
        UiElement::shutdown();     
    }

    void Compass::update(bn::fixed& map_yaw)
    {
        UiElement::update(); 

        set_sprite(bn::sprite_items::compass1.create_sprite_optional(0,-71));
        set_z_order(0);
        set_angle(map_yaw);
    }
}