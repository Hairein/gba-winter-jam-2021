#include "bn_keypad.h"

#include "bn_sprite_items_button_back.h"

#include "credits.h"

namespace mks
{
    Credits::Credits()
    {

    }

    Credits::~Credits()
    {

    }
        
    void Credits::init()
    {
        next_game_state = GameState::GAMESTATE_NONE;

        button_back_sprite = bn::sprite_items::button_back.create_sprite_optional(-100,68);  
    }

    void Credits::shutdown()
    {
        button_back_sprite.reset();
    }

    void Credits::update()
    {
        if(bn::keypad::b_released())
        {
            next_game_state = GameState::GAMESTATE_TITLE;
            return; 
        }
    }

    GameState Credits::change_game_state()
    {
        return next_game_state;
    }
}