#ifndef MKS_GAME_H
#define MKS_GAME_H

#include "bn_core.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"

#include "globals.h"
#include "vector_helper.h"
#include "explosion_handler.h"
#include "enemy_turret_handler.h"
#include "compass.h"
#include "player_helicopter.h"

namespace mks
{
    class Ingame
    {
    public:
        Ingame();
        ~Ingame();

        void init(bn::fixed_point& new_ingame_center_offset);
        void shutdown();
        void update();

        GameState change_game_state();

        bn::fixed_point get_map_position();
        bn::fixed get_map_yaw();

    protected:
        VectorHelper vector_helper;

        EnemyTurretHandler enemy_turret_handler;
        ExplosionHandler explosion_handler;

        Compass compass;
        PlayerHelicopter player_helicopter;

        GameState next_game_state;

        bn::fixed_point ingame_center_offset;

        bn::fixed_point map_center;
        bn::fixed map_yaw;

        uint16_t input_key_flags;

        void init_navigation();
        void update_input();
        void update_navigation();
        void shutdown_navigation();

        void init_map();
        void update_map();
        void shutdown_map();
        
        void init_ui();
        void update_ui();
        void shutdown_ui();
    };
}

#endif