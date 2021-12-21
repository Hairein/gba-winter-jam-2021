#ifndef MKS_ENEMY_TURRET_H
#define MKS_ENEMY_TURRET_H

#include <memory.h>

#include "bn_core.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"

#include "bn_sprite_items_enemy_turret1_base.h"
#include "bn_sprite_items_enemy_turret1_gun.h"

#include "globals.h"
#include "multi_map_entity.h"
#include "vector_helper.h"

namespace mks
{
    class Ingame;
    
    class EnemyTurret : public MultiMapEntity
    {
    public: 
        EnemyTurret(Ingame* ingame_ptr);
        ~EnemyTurret();
        
        void init(bn::fixed_point& new_position, bn::fixed& new_angle);
        void shutdown();
        void update(bn::fixed_point calculated_map_center);

    protected:
        Ingame* ingame;

        bn::fixed initial_facing_angle;
    };
}

#endif