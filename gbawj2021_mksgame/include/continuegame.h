#ifndef MKS_CONTINUEGAME_H
#define MKS_CONTINUEGAME_H

#include "bn_core.h"

#include "globals.h"

namespace mks
{
    class ContinueGame
    {
    public: 
        ContinueGame();
        ~ContinueGame();
        
        void init();
        void update();

        GameState change_game_state();
    
    protected:
        GameState next_game_state;
    };
}

#endif