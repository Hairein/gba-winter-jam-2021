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
#include "player_shot.h"
#include "vector_helper.h"
#include "hit_handler.h"

namespace mks
{
    class PlayerShotHandler
    {
    public: 
        PlayerShotHandler();
        ~PlayerShotHandler();
        
        void init();
        void shutdown();
        void update(std::unique_ptr<VectorHelper>& vector_helper, std::unique_ptr<HitHandler>& hit_handler, bn::fixed_point& map_center, bn::fixed& map_yaw);
       
        bool spawn(bn::fixed_point& map_position, bn::fixed& map_angle);

    protected:
        std::vector<PlayerShot> shots;
    };
}

#endif