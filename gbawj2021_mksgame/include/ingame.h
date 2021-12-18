#ifndef MKS_GAME_H
#define MKS_GAME_H

#include <memory>

#include "bn_core.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"

#include "globals.h"
#include "vector_helper.h"
#include "explosion_handler.h"
#include "crater_handler.h"
#include "enemy_turret_handler.h"
#include "enemy_tank_handler.h"
#include "enemy_helicopter_handler.h"
#include "pow_cage_handler.h"
#include "pow_handler.h"
#include "compass.h"
#include "health_display.h"
#include "pows_left_display.h"
#include "player_helicopter.h"
#include "rtb_message_display.h"

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
        std::unique_ptr<VectorHelper> vector_helper;
        std::unique_ptr<bn::random> random;

        std::unique_ptr<EnemyTurretHandler> enemy_turret_handler;
        std::unique_ptr<EnemyTankHandler> enemy_tank_handler;
        std::unique_ptr<EnemyHelicopterHandler> enemy_helicopter_handler;
        std::unique_ptr<PowCageHandler> pow_cage_handler;
        std::unique_ptr<PowHandler> pow_handler;
        std::unique_ptr<ExplosionHandler> explosion_handler;
        std::unique_ptr<CraterHandler> crater_handler;

        std::unique_ptr<Compass> compass;
        std::unique_ptr<HealthDisplay> health_display;
        std::unique_ptr<PowsLeftDisplay> pows_left_display;
        std::unique_ptr<PlayerHelicopter> player_helicopter;
        std::unique_ptr<RtbMessageDisplay> rtb_message_display;

        GameState next_game_state;

        bn::fixed_point ingame_center_offset;

        bn::fixed_point map_center;
        bn::fixed map_yaw;

        uint16_t input_key_flags;

        bn::fixed player_health_percent;
        int pows_initial;
        int pows_left;
        
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