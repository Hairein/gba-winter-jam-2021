#include "bn_keypad.h"

#include "bn_sprite_items_button_back.h"

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

        button_back_sprite = bn::sprite_items::button_back.create_sprite_optional(-100,68);  
    }

    void StartGame::shutdown()
    {
        button_back_sprite.reset();
    }

    void StartGame::update()
    {
        if(bn::keypad::a_released())
        {
            next_game_state = GameState::INGAME;
            return; 
        }
        else if(bn::keypad::b_released())
        {
            next_game_state = GameState::TITLE;
            return; 
        }
    }

    GameState StartGame::change_game_state()
    {
        return next_game_state;
    }
}