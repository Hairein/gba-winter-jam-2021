#include "bn_keypad.h"

#include "continuegame.h"

namespace mks
{
    ContinueGame::ContinueGame()
    {

    }

    ContinueGame::~ContinueGame()
    {

    }
        
    void ContinueGame::init()
    {
        next_game_state = GameState::NONE;
    }

    void ContinueGame::update()
    {
        if(bn::keypad::start_released())
        {
            next_game_state = GameState::INGAME;
            return; 
        }
    }

    GameState ContinueGame::change_game_state()
    {
        return next_game_state;
    }
}