#ifndef MKS_ENEMY_HELICOPTER_H
#define MKS_ENEMY_HELICOPTER_H

#include <memory.h>

#include "bn_core.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"

#include "bn_sprite_items_enemy_heli.h"

#include "globals.h"
#include "map_entity.h"

namespace mks
{
    class Ingame;
    class VectorHelper;

    class EnemyHelicopter : public MapEntity
    {
    public: 
        EnemyHelicopter(Ingame* ingame_ptr);
        ~EnemyHelicopter();
        
        void init(bn::fixed_point& new_position, bn::fixed& new_angle);
        void shutdown();
        void update(bn::fixed_point calculated_map_center);

        void take_damage(bn::fixed damage);

        void set_tactics_behaviour(TacticsBehaviour new_tactics_behaviour);

    protected:
        Ingame* ingame;

        bn::fixed initial_angle;
        bn::fixed_point initial_position;
        TacticsBehaviour tactics_behaviour;
        bn::fixed health;
    };
}

#endif