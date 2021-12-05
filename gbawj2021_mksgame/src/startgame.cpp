#include "bn_keypad.h"

#include "startgame.h"

namespace mks
{
    StartGame::StartGame()
    {

    }

    StartGame::~StartGame()
    {

    }
        
    void StartGame::init()
    {
        next_game_state = GameState::NONE;
    }

    void StartGame::update()
    {
        if(bn::keypad::start_released())
        {
            next_game_state = GameState::INGAME;
            return; 
        }
    }

    GameState StartGame::change_game_state()
    {
        return next_game_state;
    }
}