#include "bn_keypad.h"

#include "title.h"

namespace mks
{
    Title::Title()
    {

    }

    Title::~Title()
    {

    }
        
    void Title::init()
    {
        next_game_state = GameState::NONE;
    }

    void Title::update()
    {
        if(bn::keypad::start_released())
        {
            next_game_state = GameState::INGAME;
            return; 
        }
    }

    GameState Title::change_game_state()
    {
        return next_game_state;
    }
}