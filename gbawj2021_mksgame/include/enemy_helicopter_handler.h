#ifndef MKS_ENEMY_HELI_HANDLER_H
#define MKS_ENEMY_HELI_HANDLER_H

#include <memory.h>

#include "bn_core.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_vector.h"

#include "globals.h"
#include "enemy_helicopter.h"
#include "vector_helper.h"

namespace mks
{
    class EnemyHelicopterHandler
    {
    public: 
        EnemyHelicopterHandler();
        ~EnemyHelicopterHandler();
        
        void init();
        void shutdown();
        void update(std::unique_ptr<VectorHelper>& vector_helper, bn::fixed_point& map_center, bn::fixed& map_yaw);
       
        bool spawn_enemy_helicopter(bn::fixed_point& map_position, bn::fixed& map_angle);

    protected:
        bn::vector<EnemyHelicopter,DEFAULT_SPRITE_VECTOR_SIZE> enemy_helis;
    };
}

#endif