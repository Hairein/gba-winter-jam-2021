#ifndef MKS_PLAYER_SHOT_HANDLER_H
#define MKS_PLAYER_SHOT_HANDLER_H

#include <memory.h>
#include <vector>

#include "bn_core.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_vector.h"

#include "globals.h"

namespace mks
{
    class Ingame;
    class PlayerShot;
    
    class PlayerShotHandler
    {
    public: 
        PlayerShotHandler(Ingame* ingame_ptr);
        ~PlayerShotHandler();
        
        void init();
        void shutdown();
        void update(bn::fixed_point calculated_map_center);
       
        bool spawn(bn::fixed_point& map_position, bn::fixed& map_angle);

    protected:
        Ingame* ingame;

        std::vector<PlayerShot> shots;
    };
}

#endif