#include "bn_keypad.h"
#include "bn_log.h"

#include "ingame.h"

namespace mks
{
    Ingame::Ingame()
    {
    }
    
    Ingame::~Ingame()
    {
    }

    void Ingame::init(bn::fixed_point& new_ingame_center_offset)
    {
        next_game_state = GameState::GAMESTATE_NONE;

        ingame_center_offset = new_ingame_center_offset;

        init_navigation();

        init_ui();
        init_map();
    }

    void Ingame::shutdown()
    {
        shutdown_navigation();
        
        shutdown_ui();
        shutdown_map();
    }

    void Ingame::update()
    {
        if(bn::keypad::start_released())
        {
            next_game_state = GameState::GAMESTATE_TITLE;
            return;
        }

        update_navigation();

        update_ui();
        update_map();
    }

    bn::fixed_point Ingame::get_player_position()
    {
        return map_center;
    }

    bn::fixed Ingame::get_player_yaw_rotation()
    {
        return map_yaw;
    }

    GameState Ingame::change_game_state()
    {
        return next_game_state;
    }

    void Ingame::init_navigation()
    {
        map_center.set_x(0);
        map_center.set_y(0);
        map_yaw = 0;
    }

    void Ingame::update_navigation()
    {
        if(bn::keypad::left_held())
        {
            map_yaw -= bn::fixed(PLAYER_TURN_SPEED);
        }
        else if(bn::keypad::right_held())
        {
            map_yaw += bn::fixed(PLAYER_TURN_SPEED);
        }

        while(map_yaw < bn::fixed(0)) map_yaw += bn::fixed(360);
        while(map_yaw >= bn::fixed(360)) map_yaw -= bn::fixed(360);
 
        // ---
        auto floored_yaw = map_yaw.floor_integer();
        auto offsetUnitVectorX = vector_helper.get_rotated_unit_vector_x(floored_yaw);
        auto offsetUnitVectorY = vector_helper.get_rotated_unit_vector_y(floored_yaw);

        if(bn::keypad::a_held())
        {
            map_center.set_x(map_center.x() + (offsetUnitVectorX.x() * bn::fixed(PLAYER_PAN_SPEED)));
            map_center.set_y(map_center.y() + (offsetUnitVectorX.y() * bn::fixed(PLAYER_PAN_SPEED)));
        }
        else if(bn::keypad::b_held())
        {
            map_center.set_x(map_center.x() - (offsetUnitVectorX.x() * bn::fixed(PLAYER_PAN_SPEED)));
            map_center.set_y(map_center.y() - (offsetUnitVectorX.y() * bn::fixed(PLAYER_PAN_SPEED)));
        }

        if(bn::keypad::down_held())
        {
            map_center.set_x(map_center.x() - (offsetUnitVectorY.x() * bn::fixed(PLAYER_BACK_SPEED)));
            map_center.set_y(map_center.y() - (offsetUnitVectorY.y() * bn::fixed(PLAYER_BACK_SPEED)));
        }
        else if(bn::keypad::up_held())
        {
            map_center.set_x(map_center.x() + (offsetUnitVectorY.x() * bn::fixed(PLAYER_FORWARD_SPEED)));
            map_center.set_y(map_center.y() + (offsetUnitVectorY.y() * bn::fixed(PLAYER_FORWARD_SPEED)));
        }
    }

    void Ingame::shutdown_navigation()
    {
    }

    void Ingame::init_map()
    {
        enemy_turret_handler.init();

        // TEST
        enemy_turret_handler.spawn_enemy_turret(bn::fixed_point(-40, -40), 0, 0);
        enemy_turret_handler.spawn_enemy_turret(bn::fixed_point(40, -40), 0, 90);
        enemy_turret_handler.spawn_enemy_turret(bn::fixed_point(-40, 40), 0, 170);
        enemy_turret_handler.spawn_enemy_turret(bn::fixed_point(40, 40), 0, 300);

        explosion_handler.init();
    }

    void Ingame::update_map()
    {
        auto rotated_ingame_center_offset = vector_helper.rotate_vector(ingame_center_offset, map_yaw);
        auto calculated_ingame_map_center = map_center - rotated_ingame_center_offset;

        enemy_turret_handler.update(vector_helper, calculated_ingame_map_center, map_yaw);
        explosion_handler.update(vector_helper, calculated_ingame_map_center, map_yaw);
    }
    
    void Ingame::shutdown_map()
    {
        enemy_turret_handler.shutdown();
        explosion_handler.shutdown();
    }

    void Ingame::init_ui()
    {
        player_helicopter.init();
        player_helicopter.set_sprite(bn::sprite_items::player_heli_center.create_sprite_optional(0,40,2));
        player_helicopter.set_z_order(2);
        
        compass.init();
        compass.set_sprite(bn::sprite_items::compass1.create_sprite_optional(0,-71));
        compass.set_z_order(0);
    }

    void Ingame::update_ui()
    {
        player_helicopter.update();

        compass.set_angle(map_yaw);
        compass.update();
    }

    void Ingame::shutdown_ui()
    {
        player_helicopter.shutdown();
        compass.shutdown();
    }
}