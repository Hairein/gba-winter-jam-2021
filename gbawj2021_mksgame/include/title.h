#ifndef MKS_TITLE_H
#define MKS_TITLE_H

#include "bn_core.h"

#include "globals.h"

namespace mks
{
    class Title
    {
    public: 
        Title();
        ~Title();
        
        void init();
        void update();

        GameState change_game_state();
    
    protected:
        GameState next_game_state;
    };
}

#endif