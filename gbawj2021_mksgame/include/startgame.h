#ifndef MKS_STARTGAME_H
#define MKS_STARTGAME_H

#include "bn_core.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"

#include "globals.h"

namespace mks
{
    class StartGame
    {
    public: 
        StartGame();
        ~StartGame();
        
        void init();
        void shutdown();
        void update();

        GameState change_game_state();
    
    protected:
        GameState next_game_state;

        bn::optional<bn::sprite_ptr> button_back_sprite;
    };
}

#endif