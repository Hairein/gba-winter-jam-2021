#ifndef MKS_GAME_H
#define MKS_GAME_H

#include "bn_fixed.h"
#include "bn_fixed_point.h"

#include "globals.h"
#include "vectorhelper.h"

namespace mks
{
    class Ingame
    {
    public:
        Ingame();
        ~Ingame();

        void init();
        void update();

        GameState change_game_state();

        bn::fixed_point get_player_position();
        bn::fixed get_player_yaw_rotation();

    protected:
        VectorHelper vectorHelper;

        GameState next_game_state;

        bn::fixed_point player_position;
        bn::fixed player_yaw_rotation;
    };
}

#endif