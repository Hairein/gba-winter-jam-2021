#ifndef MKS_PLAYER_HELICOPTER_H
#define MKS_PLAYER_HELICOPTER_H

#include "bn_core.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"

#include "bn_sprite_items_player_heli1.h"

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
        void update(uint16_t input_flags, bn::fixed_point& ingame_center_offset);

    protected:
        int rotor_counter = 0;

        PitchState player_pitch_state = PITCHSTATE_CENTER;
        int pitch_state_counter = 0;
        int pitch_state_zero = 0;
        int pitch_state_min = -15;
        int pitch_state_max = 15;

        void evaluate_input(uint16_t input_flags);
    };
}

#endif