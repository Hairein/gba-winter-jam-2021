#include "player_helicopter.h"

namespace mks
{
    PlayerHelicopter::PlayerHelicopter()
    {
        active = false;
    }

    PlayerHelicopter::~PlayerHelicopter()
    {
    }
        
    void PlayerHelicopter::init()
    {   
        UiElement::init();    
    }

    void PlayerHelicopter::shutdown()
    {
        UiElement::shutdown();     
    }

    void PlayerHelicopter::update(uint16_t& input_flags,bn::fixed_point& ingame_center_offset)
    {
        UiElement::update(); 

        evaluate_input(input_flags);

        int pitch_offset = 0;
        if(player_pitch_state == PITCHSTATE_FORWARD_HALF) pitch_offset = 5;
        else if(player_pitch_state == PITCHSTATE_CENTER) pitch_offset = 5;
        else if(player_pitch_state == PITCHSTATE_BACKWARD_HALF) pitch_offset = 5;
        else if(player_pitch_state == PITCHSTATE_BACKWARD_FULL) pitch_offset = 10;
        
        int roll_offset = 0;
        if(player_roll_state == ROLLSTATE_LEFT_HALF) roll_offset = 1;
        else if(player_roll_state == ROLLSTATE_CENTER) roll_offset = 2;
        else if(player_roll_state == ROLLSTATE_RIGHT_HALF) roll_offset = 3;
        else if(player_roll_state == ROLLSTATE_RIGHT_FULL) roll_offset = 4;
        
        int sprite_index = pitch_offset + roll_offset;

        set_sprite(bn::sprite_items::player_heli.create_sprite_optional(ingame_center_offset.x(), ingame_center_offset.y(), sprite_index));
        set_z_order(2);
    }

    void PlayerHelicopter::evaluate_input(uint16_t& input_flags)
    {
        // Left/Right
        if(input_flags & INPUT_LEFT)
        {
            roll_state_counter -= 1;   

            if(roll_state_counter < roll_state_min) roll_state_counter = roll_state_min;         
        }
        else if(input_flags & INPUT_RIGHT)
        {
            roll_state_counter += 1;                 

            if(roll_state_counter > roll_state_max) roll_state_counter = roll_state_max;         
        }
        else
        {
            if(roll_state_counter < 0) roll_state_counter++;
            if(roll_state_counter > 0) roll_state_counter--;
        }

        if(roll_state_counter < -10)
        {
            player_roll_state = ROLLSTATE_LEFT_FULL;
        }
        else if(roll_state_counter >= -10 && roll_state_counter < -5)
        {
            player_roll_state = ROLLSTATE_LEFT_HALF;
        }
        else if(roll_state_counter >= 5 && roll_state_counter < 10)
        {
            player_roll_state = ROLLSTATE_RIGHT_HALF;
        }
        else if(roll_state_counter > 10)
        {
            player_roll_state = ROLLSTATE_RIGHT_FULL;
        }
        else
        {
            player_roll_state = ROLLSTATE_CENTER;
        }

        // Up/Down
        if(input_flags & INPUT_DOWN)
        {
            pitch_state_counter -= 1;   

            if(pitch_state_counter < pitch_state_min) pitch_state_counter = pitch_state_min;         
        }
        else if(input_flags & INPUT_UP)
        {
            pitch_state_counter += 1;                 

            if(pitch_state_counter > pitch_state_max) pitch_state_counter = pitch_state_max;         
        }
        else
        {
            if(pitch_state_counter < 0) pitch_state_counter++;
            if(pitch_state_counter > 0) pitch_state_counter--;
        }

        if(pitch_state_counter < -10)
        {
            player_pitch_state = PITCHSTATE_BACKWARD_FULL;
        }
        else if(pitch_state_counter >= -10 && pitch_state_counter < -5)
        {
            player_pitch_state = PITCHSTATE_BACKWARD_HALF;
        }
        else if(pitch_state_counter >= 5 && pitch_state_counter < 10)
        {
            player_pitch_state = PITCHSTATE_FORWARD_HALF;
        }
        else if(pitch_state_counter > 10)
        {
            player_pitch_state = PITCHSTATE_FORWARD_FULL;
        }
        else
        {
            player_pitch_state = PITCHSTATE_CENTER;
        }
    }
}