#ifndef MKS_SETTINGS_H
#define MKS_SETTINGS_H

#include "bn_core.h"

#include "globals.h"

namespace mks
{
    class Settings
    {
    public: 
        Settings();
        ~Settings();
        
        void init();
        void update();

        GameState change_game_state();
    
    protected:
        GameState next_game_state;
    };
}

#endif