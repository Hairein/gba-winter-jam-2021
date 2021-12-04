#ifndef MKS_NEWGAME_H
#define MKS_NEWGAME_H

#include "bn_core.h"

#include "globals.h"

namespace mks
{
    class NewGame
    {
    public: 
        NewGame();
        ~NewGame();
        
        void init();
        void update();

        GameState change_game_state();
    
    protected:
        GameState next_game_state;
    };
}

#endif