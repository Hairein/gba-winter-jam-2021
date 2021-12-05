#ifndef MKS_STARTGAME_H
#define MKS_STARTGAME_H

#include "bn_core.h"

#include "globals.h"

namespace mks
{
    class StartGame
    {
    public: 
        StartGame();
        ~StartGame();
        
        void init();
        void update();

        GameState change_game_state();
    
    protected:
        GameState next_game_state;
    };
}

#endif