#ifndef MKS_PLAYER_HELICOPTER_H
#define MKS_PLAYER_HELICOPTER_H

#include "bn_core.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"

#include "bn_sprite_items_player_heli_forward.h"
#include "bn_sprite_items_player_heli_center.h"
#include "bn_sprite_items_player_heli_backward.h"

#include "globals.h"
#include "ui_element.h"

namespace mks
{
    class PlayerHelicopter : public UiElement
    {
    public: 
        PlayerHelicopter();
        ~PlayerHelicopter();
        
        void init();
        void shutdown();
        void update(uint16_t input_flags);

    protected:
        PitchState player_pitch_state;
        int pitch_state_counter = 0;
        int pitch_state_zero = 0;
        int pitch_state_min = -15;
        int pitch_state_max = 15;
        RollState player_roll_state;
        int roll_state_counter = 0;
        int roll_state_zero = 0;
        int roll_state_min = -15;
        int roll_state_max = 15;
    };
}

#endif