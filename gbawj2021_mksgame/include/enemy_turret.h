#ifndef MKS_ENEMY_TURRET_H
#define MKS_ENEMY_TURRET_H

#include "bn_core.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"

#include "bn_sprite_items_turret_base_rotations.h"
#include "bn_sprite_items_turret_gun_rotations.h"

#include "globals.h"
#include "dual_map_entity.h"
#include "vector_helper.h"

namespace mks
{
    class EnemyTurret : public DualMapEntity
    {
    public: 
        EnemyTurret();
        ~EnemyTurret();
        
        void init(bn::fixed_point& new_position, bn::fixed& new_angle,
            int facing_angle);
        void shutdown();
        void update(VectorHelper& vector_helper, bn::fixed_point& map_center, bn::fixed& map_yaw);

    protected:
        int initial_facing_angle;
    };
}

#endif