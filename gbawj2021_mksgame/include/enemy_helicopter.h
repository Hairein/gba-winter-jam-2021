#ifndef MKS_ENEMY_HELICOPTER_H
#define MKS_ENEMY_HELICOPTER_H

#include "bn_core.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"

#include "bn_sprite_items_enemy_heli.h"

#include "globals.h"
#include "map_entity.h"
#include "vector_helper.h"

namespace mks
{
    class EnemyHelicopter : public MapEntity
    {
    public: 
        EnemyHelicopter();
        ~EnemyHelicopter();
        
        void init(bn::fixed_point& new_position, bn::fixed& new_angle);
        void shutdown();
        void update(VectorHelper& vector_helper, bn::fixed_point& map_center, bn::fixed& map_yaw);

    protected:
        bn::fixed initial_facing_angle;

        PitchState player_pitch_state = PITCHSTATE_CENTER;
        int pitch_state_counter = 0;
        int pitch_state_zero = 0;
        int pitch_state_min = -15;
        int pitch_state_max = 15;
        RollState player_roll_state = ROLLSTATE_CENTER;
        int roll_state_counter = 0;
        int roll_state_zero = 0;
        int roll_state_min = -15;
        int roll_state_max = 15;
    };
}

#endif