#ifndef MKS_EXPLOSION_HANDLER_H
#define MKS_EXPLOSION_HANDLER_H

#include "bn_core.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_vector.h"

#include "globals.h"
#include "explosion.h"

namespace mks
{
    class ExplosionHandler
    {
    public: 
        ExplosionHandler();
        ~ExplosionHandler();
        
        void init();
        void shutdown();
        void update(bn::fixed_point map_center, bn::fixed map_yaw);
       
        bool spawn_explosion(bn::fixed_point map_position, bn::fixed map_angle);

    protected:
        bn::vector<Explosion,DEFAULT_SPRITE_VECTOR_SIZE> explosions;
    };
}

#endif