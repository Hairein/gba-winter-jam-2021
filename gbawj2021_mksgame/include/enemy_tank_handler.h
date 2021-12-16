#ifndef MKS_ENEMY_TANK_HANDLER_H
#define MKS_ENEMY_TANK_HANDLER_H

#include "bn_core.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_vector.h"

#include "globals.h"
#include "enemy_tank.h"
#include "vector_helper.h"

namespace mks
{
    class EnemyTankHandler
    {
    public: 
        EnemyTankHandler();
        ~EnemyTankHandler();
        
        void init();
        void shutdown();
        void update(VectorHelper& vector_helper, bn::fixed_point& map_center, bn::fixed& map_yaw);
       
        bool spawn_enemy_tank(bn::fixed_point map_position, bn::fixed map_angle);

    protected:
        bn::vector<EnemyTank,DEFAULT_SPRITE_VECTOR_SIZE> enemy_tanks;
    };
}

#endif