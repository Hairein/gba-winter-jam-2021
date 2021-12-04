#ifndef MKS_CREDITS_H
#define MKS_CREDITS_H

#include "bn_core.h"

#include "globals.h"

namespace mks
{
    class Credits
    {
    public: 
        Credits();
        ~Credits();
        
        void init();
        void update();

        GameState change_game_state();
    
    protected:
        GameState next_game_state;
    };
}

#endif