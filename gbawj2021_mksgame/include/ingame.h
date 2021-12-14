#ifndef MKS_GAME_H
#define MKS_GAME_H

#include "bn_core.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"

#include "bn_sprite_items_player_heli_forward.h"
#include "bn_sprite_items_player_heli_center.h"
#include "bn_sprite_items_player_heli_backward.h"
#include "bn_sprite_items_compass1.h"
#include "bn_sprite_items_turret_base_rotations.h"
#include "bn_sprite_items_turret_gun_rotations.h"

#include "globals.h"
#include "vector_helper.h"
#include "explosion_handler.h"
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

        bn::fixed_point get_player_position();
        bn::fixed get_player_yaw_rotation();

    protected:
        VectorHelper vector_helper;

        ExplosionHandler explosion_handler;

        Compass compass;
        PlayerHelicopter player_helicopter;

        GameState next_game_state;

        bn::fixed_point ingame_center_offset;

        bn::fixed_point map_center;
        bn::fixed map_yaw;

        void init_map();
        void init_ui();
        void update_map();
        void update_ui();
        void shutdown_map();
        void shutdown_ui();
    };
}

#endif