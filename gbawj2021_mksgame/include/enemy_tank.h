#ifndef MKS_ENEMY_TANK_H
#define MKS_ENEMY_TANK_H

#include "bn_core.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"

#include "bn_sprite_items_enemy_tank_tracks.h"
#include "bn_sprite_items_enemy_tank_turret.h"

#include "globals.h"
#include "dual_map_entity.h"
#include "vector_helper.h"

namespace mks
{
    class EnemyTank : public DualMapEntity
    {
    public: 
        EnemyTank();
        ~EnemyTank();
        
        void init(bn::fixed_point& new_position, bn::fixed& new_angle);
        void shutdown();
        void update(VectorHelper& vector_helper, bn::fixed_point& map_center, bn::fixed& map_yaw);

    protected:
        bn::fixed initial_facing_angle;
    };
}

#endif