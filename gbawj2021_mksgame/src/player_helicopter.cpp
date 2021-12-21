#include "ingame.h"

#include "player_helicopter.h"

namespace mks
{
    PlayerHelicopter::PlayerHelicopter(Ingame* ingame_ptr)
    {
        this->ingame = ingame_ptr;

        active = false;
    }

    PlayerHelicopter::~PlayerHelicopter()
    {
    }
        
    void PlayerHelicopter::init()
    {   
        UiElement::init(); 

        rotor_counter = 0;   
    }

    void PlayerHelicopter::shutdown()
    {
        UiElement::shutdown();     
    }

    void PlayerHelicopter::update()
    {
        UiElement::update(); 

        evaluate_input();

        int pitch_offset = 0;
        if(player_pitch_state == PITCHSTATE_FORWARD_HALF) pitch_offset = 3;
        else if(player_pitch_state == PITCHSTATE_CENTER) pitch_offset = 6;
        else if(player_pitch_state == PITCHSTATE_BACKWARD_HALF) pitch_offset = 9;
        else if(player_pitch_state == PITCHSTATE_BACKWARD_FULL) pitch_offset = 12;
                
        // int sprite_index = pitch_offset + roll_offset;
        int sprite_index = 0;
        switch(rotor_counter)
        {
            case 0: sprite_index = pitch_offset; break;
            case 2: sprite_index = pitch_offset + 2; break;
            case 1: 
            case 3: 
            default: sprite_index = pitch_offset + 1; break;
        }

        auto ingame_center_offset = ingame->get_ingame_center_offset();
        set_sprite(bn::sprite_items::player_heli1.create_sprite_optional(ingame_center_offset.x(), ingame_center_offset.y(), sprite_index));
        set_z_order(2);

        rotor_counter++;
        while(rotor_counter >= MAX_PLAYER_ROTOR_INDEX) rotor_counter -= MAX_PLAYER_ROTOR_INDEX; 
    }

    void PlayerHelicopter::evaluate_input()
    {
        auto input_flags = ingame->get_input_key_flags();

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