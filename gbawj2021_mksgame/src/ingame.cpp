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

        player_health_percent = bn::fixed(100);
        pows_left = 15; // TODO Determine nos pows to be rescued in map 

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
        update_input();

        if(input_key_flags & INPUT_START)
        {
            next_game_state = GameState::GAMESTATE_TITLE;
            return;
        }

        // TEST
        // if(bn::keypad::r_released())
        // {
        //     crater_handler.spawn(random, bn::fixed_point(map_center.x() - bn::fixed(40), map_center.y() - bn::fixed(40)));
        // }

        update_navigation();

        update_ui();
        update_map();
    }

    bn::fixed_point Ingame::get_map_position()
    {
        return map_center;
    }

    bn::fixed Ingame::get_map_yaw()
    {
        return map_yaw;
    }

    GameState Ingame::change_game_state()
    {
        return next_game_state;
    }

    void Ingame::update_input()
    {
        input_key_flags = 0x0000;

        if(bn::keypad::a_held()) input_key_flags |= INPUT_A;   
        if(bn::keypad::b_held()) input_key_flags |= INPUT_B;   
        if(bn::keypad::select_held()) input_key_flags |= INPUT_SELECT;   
        if(bn::keypad::start_held()) input_key_flags |= INPUT_START;   
        if(bn::keypad::right_held()) input_key_flags |= INPUT_RIGHT;   
        if(bn::keypad::left_held()) input_key_flags |= INPUT_LEFT;   
        if(bn::keypad::up_held()) input_key_flags |= INPUT_UP;   
        if(bn::keypad::down_held()) input_key_flags |= INPUT_DOWN;   
        if(bn::keypad::r_held()) input_key_flags |= INPUT_R;   
        if(bn::keypad::l_held()) input_key_flags |= INPUT_L;   
    }

    void Ingame::init_navigation()
    {
        map_center.set_x(0);
        map_center.set_y(0);
        map_yaw = 0;
    }

    void Ingame::update_navigation()
    {
        if(input_key_flags & INPUT_LEFT)
        {
            map_yaw -= bn::fixed(PLAYER_TURN_SPEED);
        }
        else if(input_key_flags & INPUT_RIGHT)
        {
            map_yaw += bn::fixed(PLAYER_TURN_SPEED);
        }

        while(map_yaw < bn::fixed(0)) map_yaw += bn::fixed(360);
        while(map_yaw >= bn::fixed(360)) map_yaw -= bn::fixed(360);
 
        // ---
        auto floored_yaw = map_yaw.floor_integer();
        auto offsetUnitVectorX = vector_helper.get_rotated_unit_vector_x(floored_yaw);
        auto offsetUnitVectorY = vector_helper.get_rotated_unit_vector_y(floored_yaw);

        if(input_key_flags & INPUT_A)
        {
            map_center.set_x(map_center.x() + (offsetUnitVectorX.x() * bn::fixed(PLAYER_PAN_SPEED)));
            map_center.set_y(map_center.y() + (offsetUnitVectorX.y() * bn::fixed(PLAYER_PAN_SPEED)));
        }
        else if(input_key_flags & INPUT_B)
        {
            map_center.set_x(map_center.x() - (offsetUnitVectorX.x() * bn::fixed(PLAYER_PAN_SPEED)));
            map_center.set_y(map_center.y() - (offsetUnitVectorX.y() * bn::fixed(PLAYER_PAN_SPEED)));
        }

        if(input_key_flags & INPUT_DOWN)
        {
            map_center.set_x(map_center.x() - (offsetUnitVectorY.x() * bn::fixed(PLAYER_BACK_SPEED)));
            map_center.set_y(map_center.y() - (offsetUnitVectorY.y() * bn::fixed(PLAYER_BACK_SPEED)));
        }
        else if(input_key_flags & INPUT_UP)
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
        enemy_turret_handler = new EnemyTurretHandler();
        enemy_turret_handler->init(); 

        enemy_tank_handler = new EnemyTankHandler();
        enemy_tank_handler->init();

        enemy_helicopter_handler = new EnemyHelicopterHandler();
        enemy_helicopter_handler->init();

        pow_cage_handler = new PowCageHandler();
        pow_cage_handler->init();        

        pow_handler = new PowHandler();
        pow_handler->init();

        explosion_handler = new ExplosionHandler();
        explosion_handler->init();

        crater_handler = new CraterHandler();
        crater_handler->init();
    }

    void Ingame::update_map()
    {
        auto rotated_ingame_center_offset = vector_helper.rotate_vector(ingame_center_offset, map_yaw);
        auto calculated_ingame_map_center = map_center - rotated_ingame_center_offset;

        enemy_turret_handler->update(vector_helper, calculated_ingame_map_center, map_yaw);
        enemy_tank_handler->update(vector_helper, calculated_ingame_map_center, map_yaw);
        enemy_helicopter_handler->update(vector_helper, calculated_ingame_map_center, map_yaw);
        pow_cage_handler->update(vector_helper, calculated_ingame_map_center, map_yaw);
        pow_handler->update(vector_helper, calculated_ingame_map_center, map_yaw);
        explosion_handler->update(vector_helper, calculated_ingame_map_center, map_yaw);
        crater_handler->update(vector_helper, calculated_ingame_map_center, map_yaw);
    }
    
    void Ingame::shutdown_map()
    {
        enemy_turret_handler->shutdown();
        delete enemy_turret_handler;

        enemy_tank_handler->shutdown();
        delete enemy_tank_handler;

        enemy_helicopter_handler->shutdown();
        delete enemy_helicopter_handler;

        pow_cage_handler->shutdown();
        delete pow_cage_handler;

        pow_handler->shutdown();
        delete pow_handler;

        explosion_handler->shutdown();
        delete explosion_handler;

        crater_handler->shutdown();
        delete crater_handler;
    }

    void Ingame::init_ui()
    {
        player_helicopter = new PlayerHelicopter();
        player_helicopter->init();

        compass = new Compass();
        compass->init();

        health_display = new HealthDisplay();
        health_display->init(player_health_percent);

        pows_left_display = new PowsLeftDisplay();
        pows_left_display->init(pows_left);
    }

    void Ingame::update_ui()
    {
        player_helicopter->update(input_key_flags, ingame_center_offset);
        compass->update(map_yaw);
        health_display->update(player_health_percent);
        pows_left_display->update(pows_left);
   }

    void Ingame::shutdown_ui()
    {
        player_helicopter->shutdown();
        delete player_helicopter;
        
        compass->shutdown();
        delete compass;

        health_display->shutdown();
        delete health_display;

        pows_left_display->shutdown();
        delete pows_left_display;
    }
}