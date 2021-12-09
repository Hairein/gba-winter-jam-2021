#include "bn_keypad.h"

#include "ingame.h"

namespace mks
{
    Ingame::Ingame()
    {
    }
    
    Ingame::~Ingame()
    {
    }

    void Ingame::init(bn::fixed_point new_ingame_center_offset)
    {
        next_game_state = GameState::GAMESTATE_NONE;

        ingame_center_offset = new_ingame_center_offset;

        player_position.set_x(0);
        player_position.set_y(0);
        player_yaw_rotation = 0;
 
        player_heli_sprite = bn::sprite_items::player_heli_center.create_sprite_optional(0,40,2);
        compass_sprite = bn::sprite_items::compass1.create_sprite_optional(0,-71);
    }

    void Ingame::shutdown()
    {
        player_heli_sprite.reset();
        compass_sprite.reset();
    }

    void Ingame::update()
    {
        if(bn::keypad::start_released())
        {
            next_game_state = GameState::GAMESTATE_TITLE;
            return;
        }

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

        auto offsetUnitVectorX = vectorHelper.get_rotated_unit_vector_x(player_yaw_rotation.floor_integer());
        auto offsetUnitVectorY = vectorHelper.get_rotated_unit_vector_y(player_yaw_rotation.floor_integer());

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

        update_compass();
    }

    bn::fixed_point Ingame::get_player_position()
    {
        return player_position;
    }

    bn::fixed Ingame::get_player_yaw_rotation()
    {
        return player_yaw_rotation;
    }

    GameState Ingame::change_game_state()
    {
        return next_game_state;
    }

    void Ingame::update_compass()
    {
        compass_sprite.get()->set_rotation_angle(player_yaw_rotation);
    }
}