#ifndef MKS_GAME_H
#define MKS_GAME_H

#define PLAYER_TURN_SPEED 0.5
#define PLAYER_FORWARD_SPEED 1.0
#define PLAYER_BACK_SPEED 0.75
#define PLAYER_PAN_SPEED 1.0

#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_optional.h"
#include "bn_affine_bg_ptr.h"
#include "bn_sprite_text_generator.h"

#include "VectorHelper.h"

namespace mks
{
    class Game
    {
    public:
        Game();
        ~Game();

        void init();
        void handle_player_navigation(bn::fixed_point& player_position, bn::fixed& player_yaw_rotation);

        bool quit();

    protected:
        VectorHelper vectorHelper;

        bool quit_ingame = false;
    };
}

#endif