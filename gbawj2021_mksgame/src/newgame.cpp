#include "bn_keypad.h"

#include "newgame.h"

namespace mks
{
    NewGame::NewGame()
    {

    }

    NewGame::~NewGame()
    {

    }
        
    void NewGame::init()
    {
        next_game_state = GameState::NONE;
    }

    void NewGame::update()
    {
        if(bn::keypad::start_released())
        {
            next_game_state = GameState::INGAME;
            return; 
        }
    }

    GameState NewGame::change_game_state()
    {
        return next_game_state;
    }
}