#include "player_helicopter.h"

namespace mks
{
    PlayerHelicopter::PlayerHelicopter()
    {
        active = false;
    }

    PlayerHelicopter::~PlayerHelicopter()
    {
    }
        
    void PlayerHelicopter::init()
    {   
        UiElement::init();    
    }

    void PlayerHelicopter::shutdown()
    {
        UiElement::shutdown();     
    }

    void PlayerHelicopter::update(uint16_t input_flags)
    {
        UiElement::update(); 

        set_sprite(bn::sprite_items::player_heli_center.create_sprite_optional(0,40,2));
        set_z_order(2);
    }
}