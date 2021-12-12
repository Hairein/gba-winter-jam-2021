#ifndef MKS_GAME_H
#define MKS_GAME_H

#include "bn_core.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"

#include "bn_sprite_items_player_heli_forward.h"
#include "bn_sprite_items_player_heli_center.h"
#include "bn_sprite_items_player_heli_backward.h"
#include "bn_sprite_items_compass1.h"
#include "bn_sprite_items_turret_base_rotations.h"
#include "bn_sprite_items_turret_gun_rotations.h"

#include "globals.h"
#include "vectorhelper.h"

namespace mks
{
    class Ingame
    {
    public:
        Ingame();
        ~Ingame();

        void init(bn::fixed_point new_ingame_center_offset);
        void shutdown();
        void update();

        GameState change_game_state();

        bn::fixed_point get_player_position();
        bn::fixed get_player_yaw_rotation();

    protected:
        VectorHelper vectorHelper;

        GameState next_game_state;

        bn::fixed_point ingame_center_offset;

        bn::fixed_point player_position;
        bn::fixed player_yaw_rotation;

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

        bn::optional<bn::sprite_ptr> player_heli_sprite;
        bn::optional<bn::sprite_ptr> compass_sprite;

        void update_compass();
    };
}

#endif