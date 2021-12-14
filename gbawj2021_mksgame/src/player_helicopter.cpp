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

    void PlayerHelicopter::update()
    {
        UiElement::update();     
    }
}