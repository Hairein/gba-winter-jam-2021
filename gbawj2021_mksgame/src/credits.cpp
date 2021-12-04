#include "bn_keypad.h"

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
        next_game_state = GameState::NONE;
    }

    void Credits::update()
    {
        if(bn::keypad::start_released())
        {
            next_game_state = GameState::TITLE;
            return; 
        }
    }

    GameState Credits::change_game_state()
    {
        return next_game_state;
    }
}