#include "bn_keypad.h"
#include "bn_log.h"

#include "bn_sprite_items_text_version.h"
#include "bn_sprite_items_button_a.h"
#include "bn_sprite_items_buttons_main_menu.h"

#include "title.h"

namespace mks
{
    Title::Title()
    {
        menu_index = 0;
    }

    Title::~Title()
    {
    }
        
    void Title::init()
    {
        next_game_state = GameState::NONE;

        text_main_menu_version = bn::sprite_items::text_version.create_sprite_optional(-100,-68);

        button_a_sprite = bn::sprite_items::button_a.create_sprite_optional(-16, 29);  
        
        button_main_menu_start_sprite = bn::sprite_items::buttons_main_menu.create_sprite_optional(0,28,0);
        button_main_menu_settings_sprite = bn::sprite_items::buttons_main_menu.create_sprite_optional(0,48,1);
        button_main_menu_credits_sprite = bn::sprite_items::buttons_main_menu.create_sprite_optional(0,68,2);

        update_cursor();
    }

    void Title::shutdown()
    {
        text_main_menu_version.reset();
        button_a_sprite.reset();
        button_main_menu_start_sprite.reset();
        button_main_menu_settings_sprite.reset();
        button_main_menu_credits_sprite.reset();
    }

    void Title::update()
    {
        if(bn::keypad::up_released())
        {
            menu_index -= 1;
            if(menu_index < 0)
            {
                menu_index = 2;
            }

            update_cursor();
        }
        else if(bn::keypad::down_released())
        {
            menu_index += 1;
            if(menu_index > 2)
            {
                menu_index = 0;
            }

            update_cursor();
        }
        else if(bn::keypad::a_released())
        {
            switch(menu_index)
            {
                case 0: next_game_state = GameState::START_GAME;break;
                case 1: next_game_state = GameState::SETTINGS;break;
                case 2: next_game_state = GameState::CREDITS;break;
                default: break;
            }
            return; 
        }

    }

    GameState Title::change_game_state()
    {
        return next_game_state;
    }

    void Title::update_cursor()
    {
        switch(menu_index)
        {
            case 0: button_a_sprite.get()->set_y(29);break;
            case 1: button_a_sprite.get()->set_y(49);break;
            case 2: button_a_sprite.get()->set_y(69);break;
            default: break;
        }
    }
}