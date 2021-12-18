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
        
        pows_initial = 15;// TODO Determine nos pows to be rescued in map 
        pows_left = pows_initial; 

        vector_helper.reset(new VectorHelper());
        random.reset(new bn::random());

        init_navigation();

        init_ui();
        init_map();
    }

    void Ingame::shutdown()
    {
        vector_helper.reset();
        random.reset();

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
        auto offsetUnitVectorX = vector_helper.get()->get_rotated_unit_vector_x(floored_yaw);
        auto offsetUnitVectorY = vector_helper.get()->get_rotated_unit_vector_y(floored_yaw);

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
        enemy_turret_handler.reset(new EnemyTurretHandler());
        enemy_turret_handler.get()->init(); 

        enemy_tank_handler.reset(new EnemyTankHandler());
        enemy_tank_handler.get()->init();

        enemy_helicopter_handler.reset(new EnemyHelicopterHandler());
        enemy_helicopter_handler.get()->init();

        pow_cage_handler.reset(new PowCageHandler());
        pow_cage_handler.get()->init();        

        pow_handler.reset(new PowHandler());
        pow_handler.get()->init();

        explosion_handler.reset(new ExplosionHandler());
        explosion_handler.get()->init();

        crater_handler.reset(new CraterHandler());
        crater_handler.get()->init();
    }

    void Ingame::update_map()
    {
        auto rotated_ingame_center_offset = vector_helper.get()->rotate_vector(ingame_center_offset, map_yaw);
        auto calculated_ingame_map_center = map_center - rotated_ingame_center_offset;

        enemy_turret_handler.get()->update(vector_helper, calculated_ingame_map_center, map_yaw);
        enemy_tank_handler.get()->update(vector_helper, calculated_ingame_map_center, map_yaw);
        enemy_helicopter_handler.get()->update(vector_helper, calculated_ingame_map_center, map_yaw);
        pow_cage_handler.get()->update(vector_helper, calculated_ingame_map_center, map_yaw);
        pow_handler.get()->update(vector_helper, calculated_ingame_map_center, map_yaw);
        explosion_handler.get()->update(vector_helper, calculated_ingame_map_center, map_yaw);
        crater_handler.get()->update(vector_helper, calculated_ingame_map_center, map_yaw);
    }
    
    void Ingame::shutdown_map()
    {
        enemy_turret_handler.get()->shutdown();
        enemy_turret_handler.reset();

        enemy_tank_handler.get()->shutdown();
        enemy_tank_handler.reset();

        enemy_helicopter_handler.get()->shutdown();
        enemy_helicopter_handler.reset();

        pow_cage_handler.get()->shutdown();
        pow_cage_handler.reset();

        pow_handler.get()->shutdown();
        pow_handler.reset();

        explosion_handler.get()->shutdown();
        explosion_handler.reset();

        crater_handler.get()->shutdown();
        crater_handler.reset();
    }

    void Ingame::init_ui()
    {
        player_helicopter.reset(new PlayerHelicopter());
        player_helicopter.get()->init();

        compass.reset(new Compass());
        compass.get()->init();

        health_display.reset(new HealthDisplay());
        health_display.get()->init(player_health_percent);

        pows_left_display.reset(new PowsLeftDisplay());
        pows_left_display.get()->init(pows_left);

        rtb_message_display.reset(new RtbMessageDisplay());
        rtb_message_display.get()->init();
    }

    void Ingame::update_ui()
    {
        player_helicopter.get()->update(input_key_flags, ingame_center_offset);
        compass.get()->update(map_yaw);
        health_display.get()->update(player_health_percent);
        pows_left_display.get()->update(pows_left);
        rtb_message_display.get()->update(pows_left == 0);
   }

    void Ingame::shutdown_ui()
    {
        player_helicopter.get()->shutdown();
        player_helicopter.reset();
        
        compass.get()->shutdown();
        compass.reset();

        health_display.get()->shutdown();
        health_display.reset();

        pows_left_display.get()->shutdown();
        pows_left_display.reset();

        rtb_message_display.get()->shutdown();
        rtb_message_display.reset();
    }
}