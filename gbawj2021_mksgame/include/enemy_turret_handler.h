#ifndef MKS_ENEMY_TURRET_HANDLER_H
#define MKS_ENEMY_TURRET_HANDLER_H

#include "bn_core.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_vector.h"

#include "globals.h"
#include "enemy_turret.h"
#include "vector_helper.h"

namespace mks
{
    class EnemyTurretHandler
    {
    public: 
        EnemyTurretHandler();
        ~EnemyTurretHandler();
        
        void init();
        void shutdown();
        void update(VectorHelper& vector_helper, bn::fixed_point& map_center, bn::fixed& map_yaw);
       
        bool spawn_enemy_turret(bn::fixed_point map_position, bn::fixed map_angle, int facing_angle);

    protected:
        bn::vector<EnemyTurret,DEFAULT_SPRITE_VECTOR_SIZE> enemy_turrets;
    };
}

#endif