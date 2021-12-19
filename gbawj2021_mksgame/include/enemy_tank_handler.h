#ifndef MKS_ENEMY_TANK_HANDLER_H
#define MKS_ENEMY_TANK_HANDLER_H

#include <memory.h>

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
        void update(std::unique_ptr<VectorHelper>& vector_helper, bn::fixed_point& map_center, bn::fixed& map_yaw);
       
        bool spawn(bn::fixed_point& map_position, bn::fixed& map_angle);

    protected:
        bn::vector<EnemyTank,DEFAULT_SPRITE_VECTOR_SIZE> enemy_tanks;
    };
}

#endif