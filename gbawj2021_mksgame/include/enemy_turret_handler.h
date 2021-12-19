#ifndef MKS_ENEMY_TURRET_HANDLER_H
#define MKS_ENEMY_TURRET_HANDLER_H

#include <memory.h>
#include <vector>

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
        void update(std::unique_ptr<VectorHelper>& vector_helper, bn::fixed_point& map_center, bn::fixed& map_yaw);
       
        bool spawn(bn::fixed_point& map_position, bn::fixed& map_angle);

    protected:
        std::vector<EnemyTurret> enemy_turrets;
    };
}

#endif