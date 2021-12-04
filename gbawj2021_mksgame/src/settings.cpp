#include "bn_keypad.h"

#include "settings.h"

namespace mks
{
    Settings::Settings()
    {

    }

    Settings::~Settings()
    {

    }
        
    void Settings::init()
    {
        next_game_state = GameState::NONE;
    }

    void Settings::update()
    {
        if(bn::keypad::start_released())
        {
            next_game_state = GameState::TITLE;
            return; 
        }
    }

    GameState Settings::change_game_state()
    {
        return next_game_state;
    }
}