#ifndef MKS_GAME_H
#define MKS_GAME_H

#include <memory>
#include <string>

#include "bn_core.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_memory.h"
#include "bn_random.h"

#include "globals.h"


namespace mks
{
    class VectorHelper;
    class MapHelper;

    class EnemyTurretHandler;
    class EnemyTankHandler;
    class EnemyHelicopterHandler;
    class PowCageHandler;
    class PowHandler;
    class ExplosionHandler;
    class HitHandler;
    class PlayerShotHandler;
    class EnemyShotHandler;
    class CraterHandler;

    class Compass;
    class HealthDisplay;
    class PowsLeftDisplay;
    class PlayerHelicopter;
    class RtbMessageDisplay;

    class Ingame
    {
    public:
        Ingame();
        ~Ingame();

        void init(bn::fixed_point& new_ingame_center_offset);
        void shutdown();
        void update();

        void log_memory(std::string msg);

        GameState change_game_state();
        bn::fixed_point& get_map_center();
        bn::fixed& get_map_yaw();

        VectorHelper* get_vector_helper() {return vector_helper.get();};
        MapHelper* get_map_helper() {return map_helper.get();};
        bn::random* get_random() {return random.get();};

        EnemyTurretHandler* get_enemy_turret_handler() {return enemy_turret_handler.get();};
        EnemyTankHandler* get_enemy_tank_handler() {return enemy_tank_handler.get();};
        EnemyHelicopterHandler* get_enemy_helicopter_handler() {return enemy_helicopter_handler.get();};
        PowCageHandler* get_pow_cage_handler() {return pow_cage_handler.get();};
        PowHandler* get_pow_handler() {return pow_handler.get();};
        ExplosionHandler* get_explosion_handler() {return explosion_handler.get();};
        HitHandler* get_hit_handler() {return hit_handler.get();};
        PlayerShotHandler* get_player_shot_handler() {return player_shot_handler.get();};
        EnemyShotHandler* get_enemy_shot_handler() {return enemy_shot_handler.get();};
        CraterHandler* get_crater_handler() {return crater_handler.get();};

        bn::fixed& get_player_health() {return player_health;};
        uint16_t& get_input_key_flags() {return input_key_flags;};
        bn::fixed_point& get_ingame_center_offset() {return ingame_center_offset;};
        int& get_pows_left() { return pows_left;};
        void decrement_pows_left() {pows_left--;};

    protected:
        std::unique_ptr<VectorHelper> vector_helper;
        std::unique_ptr<MapHelper> map_helper;
        std::unique_ptr<bn::random> random;

        std::unique_ptr<EnemyTurretHandler> enemy_turret_handler;
        std::unique_ptr<EnemyTankHandler> enemy_tank_handler;
        std::unique_ptr<EnemyHelicopterHandler> enemy_helicopter_handler;
        std::unique_ptr<PowCageHandler> pow_cage_handler;
        std::unique_ptr<PowHandler> pow_handler;
        std::unique_ptr<ExplosionHandler> explosion_handler;
        std::unique_ptr<HitHandler> hit_handler;
        std::unique_ptr<PlayerShotHandler> player_shot_handler;
        std::unique_ptr<EnemyShotHandler> enemy_shot_handler;
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

        bool end_mission;
        bool enable_player_input;
        int last_player_shot;

        bn::fixed player_health;
        int pows_initial;
        int pows_left;
        
        void init_gameplay();
        void spawn_entities();
        
        void init_navigation();
        void update_input();
        void wait_for_no_input();
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