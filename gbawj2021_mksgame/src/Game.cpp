#include "bn_fixed_point.h"
#include "bn_string.h"
#include "bn_sprite_text_generator.h"

#include "bn_regular_bg_items_test_pattern.h"
#include "bn_regular_bg_items_layout.h"

#include "bn_keypad.h"

#include "Game.h"

namespace mks
{
    Game::Game()
    {
    }
    
    Game::~Game()
    {
    }

    void Game::init()
    {
    }

    void Game::handle_player_navigation(bn::fixed_point& player_position, bn::fixed& player_yaw_rotation)
    {
        quit_ingame = bn::keypad::start_released();

        if(bn::keypad::left_held())
        {
            player_yaw_rotation -= bn::fixed(PLAYER_TURN_SPEED);
        }
        else if(bn::keypad::right_held())
        {
            player_yaw_rotation += bn::fixed(PLAYER_TURN_SPEED);
        }

        while(player_yaw_rotation >= bn::fixed(360))
        {
            player_yaw_rotation -= bn::fixed(360);
        }
        while(player_yaw_rotation < bn::fixed(0))
        {
            player_yaw_rotation += bn::fixed(360);
        }

        // ---

        auto offsetUnitVectorX = vectorHelper.getRotatedUnitVectorX(player_yaw_rotation.floor_integer());
        auto offsetUnitVectorY = vectorHelper.getRotatedUnitVectorY(player_yaw_rotation.floor_integer());

        if(bn::keypad::a_held())
        {
            player_position.set_x(player_position.x() + (offsetUnitVectorX.x() * bn::fixed(PLAYER_PAN_SPEED)));
            player_position.set_y(player_position.y() + (offsetUnitVectorX.y() * bn::fixed(PLAYER_PAN_SPEED)));
        }
        else if(bn::keypad::b_held())
        {
            player_position.set_x(player_position.x() - (offsetUnitVectorX.x() * bn::fixed(PLAYER_PAN_SPEED)));
            player_position.set_y(player_position.y() - (offsetUnitVectorX.y() * bn::fixed(PLAYER_PAN_SPEED)));
        }

        if(bn::keypad::down_held())
        {
            player_position.set_x(player_position.x() - (offsetUnitVectorY.x() * bn::fixed(PLAYER_BACK_SPEED)));
            player_position.set_y(player_position.y() - (offsetUnitVectorY.y() * bn::fixed(PLAYER_BACK_SPEED)));
        }
        else if(bn::keypad::up_held())
        {
            player_position.set_x(player_position.x() + (offsetUnitVectorY.x() * bn::fixed(PLAYER_FORWARD_SPEED)));
            player_position.set_y(player_position.y() + (offsetUnitVectorY.y() * bn::fixed(PLAYER_FORWARD_SPEED)));
        }
    }

    bool Game::quit()
    {
        return quit_ingame;
    }
}