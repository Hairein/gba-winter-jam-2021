#include "bn_core.h"
#include "bn_sprite_text_generator.h"
#include "bn_bg_palettes.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_string.h"
#include "bn_optional.h"
#include "bn_keypad.h"
#include "bn_affine_bg_ptr.h"
#include "bn_affine_bg_map_ptr.h"
#include "bn_affine_bg_map_cell.h"
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"
#include "bn_log.h"
#include "bn_span.h"
#include "bn_sprite_ptr.h"

#include "common_info.h"
#include "common_variable_8x16_sprite_font.h"

#include "bn_affine_bg_items_map0.h"
#include "bn_regular_bg_items_map_view.h"
#include "bn_regular_bg_items_credits.h"
#include "bn_regular_bg_items_title.h"

#include "globals.h"

#include "credits.h"
#include "ingame.h"
#include "startgame.h"
#include "settings.h"
#include "title.h"

int main();
void move_to_game_state(GameState new_game_state, 
    GameState& previous_game_state, 
    GameState& current_game_state,
    bn::optional<bn::affine_bg_ptr>& affine_bg,
    bn::optional<bn::regular_bg_ptr>& regular_bg,
    mks::Credits& credits,
    mks::Ingame& ingame,
    mks::StartGame& start_game,
    mks::Settings& settings,
    mks::Title& title);

int main()
{
    bn::core::init();

    bn::sprite_text_generator text_generator(common::variable_8x16_sprite_font);
    bn::bg_palettes::set_transparent_color(bn::color(4, 4, 4));

    // constexpr bn::string_view info_text_lines[] = {
    //     ""
    // };

    // common::info info("v0.1preAlpha", info_text_lines, text_generator);

    bn::optional<bn::affine_bg_ptr> main_affine_bg;
    bn::optional<bn::regular_bg_ptr> main_regular_bg;

    mks::Credits credits;
    mks::Ingame ingame;
    mks::StartGame start_game;
    mks::Settings settings;
    mks::Title title;

    GameState previous_game_state = GameState::GAMESTATE_NONE;
    GameState current_game_state = GameState::GAMESTATE_NONE;

    move_to_game_state(GameState::GAMESTATE_INIT, 
        previous_game_state, 
        current_game_state, 
        main_affine_bg, 
        main_regular_bg,
        credits,
        ingame,
        start_game,
        settings,
        title);

    while(true)
    {
        switch(current_game_state)
        {
            case GameState::GAMESTATE_INIT: // One-time initialization
                {
                    move_to_game_state(GameState::GAMESTATE_TITLE, 
                        previous_game_state, 
                        current_game_state, 
                        main_affine_bg, 
                        main_regular_bg,
                        credits,
                        ingame,
                        start_game,
                        settings,
                        title);
                }
                break;
            case GameState::GAMESTATE_CREDITS:
                {
                    credits.update();

                    if(credits.change_game_state() != GameState::GAMESTATE_NONE)
                    {
                        move_to_game_state(credits.change_game_state(), 
                            previous_game_state, 
                            current_game_state, 
                            main_affine_bg, 
                            main_regular_bg,
                            credits,
                            ingame,
                            start_game,
                            settings,
                            title);
                    }
                    else
                    {
                    }
                }
                break;
            case GameState::GAMESTATE_INGAME:
                {
                    ingame.update();

                    if(ingame.change_game_state() != GameState::GAMESTATE_NONE)
                    {
                        move_to_game_state(ingame.change_game_state(), 
                            previous_game_state, 
                            current_game_state, 
                            main_affine_bg, 
                            main_regular_bg,
                            credits,
                            ingame,
                            start_game,
                            settings,
                            title);
                    }
                    else
                    {
                        main_affine_bg.get()->set_pivot_position(ingame.get_map_position());
                        main_affine_bg.get()->set_rotation_angle(ingame.get_map_yaw());
                    }
                }
                break;
            case GameState::GAMESTATE_START_GAME:
                {
                    start_game.update();

                    if(start_game.change_game_state() != GameState::GAMESTATE_NONE)
                    {
                        move_to_game_state(start_game.change_game_state(), 
                            previous_game_state, 
                            current_game_state, 
                            main_affine_bg, 
                            main_regular_bg,
                            credits,
                            ingame,
                            start_game,
                            settings,
                            title);
                    }
                    else
                    {
                    }
                }
                break;
            case GameState::GAMESTATE_SETTINGS:
                {
                    settings.update();

                    if(settings.change_game_state() != GameState::GAMESTATE_NONE)
                    {
                        move_to_game_state(settings.change_game_state(), 
                            previous_game_state, 
                            current_game_state, 
                            main_affine_bg, 
                            main_regular_bg,
                            credits,
                            ingame,
                            start_game,
                            settings,
                            title);
                    }
                    else
                    {
                    }
                }
                break;
            case GameState::GAMESTATE_TITLE:
                {
                    title.update();

                    if(title.change_game_state() != GameState::GAMESTATE_NONE)
                    {
                        move_to_game_state(title.change_game_state(), 
                            previous_game_state, 
                            current_game_state, 
                            main_affine_bg, 
                            main_regular_bg,
                            credits,
                            ingame,
                            start_game,
                            settings,
                            title);
                    }
                    else
                    {
                    }
                }
                break;
            default:
                break;
        }

        // ---

        //info.update();

        bn::core::update();
    }
}

void move_to_game_state(GameState new_game_state, 
    GameState& previous_game_state, 
    GameState& current_game_state,
    bn::optional<bn::affine_bg_ptr>& affine_bg,
    bn::optional<bn::regular_bg_ptr>& regular_bg,
    mks::Credits& credits,
    mks::Ingame& ingame,
    mks::StartGame& start_game,
    mks::Settings& settings,
    mks::Title& title)
{
    previous_game_state = current_game_state;
    switch(previous_game_state)
    {
        case GameState::GAMESTATE_TITLE:
            {
                affine_bg.reset();
                
                regular_bg.reset();

                title.shutdown();
            }
            break;
        case GameState::GAMESTATE_START_GAME:
            {
                affine_bg.reset();
                
                regular_bg.reset();

                start_game.shutdown();
            }
            break;
        case GameState::GAMESTATE_SETTINGS:
            {
                affine_bg.reset();
                
                regular_bg.reset();

                settings.shutdown();
            }
            break;
        case GameState::GAMESTATE_CREDITS:
            {
                affine_bg.reset();
                
                regular_bg.reset();

                credits.shutdown();
            }
            break;
        case GameState::GAMESTATE_INGAME:
            {
                regular_bg.reset();

                affine_bg.reset();

                ingame.shutdown();
            }
            break;
        default:
            break;
    }

    current_game_state = new_game_state;    
    switch(current_game_state)
    {
        case GameState::GAMESTATE_TITLE:
            {
                affine_bg.reset();
                
                regular_bg.reset();
                regular_bg = bn::regular_bg_items::title.create_bg(0,0);
                regular_bg.get()->set_priority(3); 
                regular_bg.get()->set_position(bn::fixed(0), bn::fixed(0)); 

                title.init();
            }
            break;
        case GameState::GAMESTATE_START_GAME:
            {
                affine_bg.reset();
                
                regular_bg.reset();
                regular_bg = bn::regular_bg_items::map_view.create_bg(0,0);
                regular_bg.get()->set_priority(3); 
                regular_bg.get()->set_position(bn::fixed(0), bn::fixed(0)); 

                start_game.init();
            }
            break;
        case GameState::GAMESTATE_SETTINGS:
            {
                affine_bg.reset();
                
                regular_bg.reset();
                regular_bg = bn::regular_bg_items::map_view.create_bg(0,0);
                regular_bg.get()->set_priority(3); 
                regular_bg.get()->set_position(bn::fixed(0), bn::fixed(0)); 

                settings.init();
            }
            break;
        case GameState::GAMESTATE_CREDITS:
            {
                affine_bg.reset();
                
                regular_bg.reset();
                regular_bg = bn::regular_bg_items::credits.create_bg(0,0);
                regular_bg.get()->set_priority(3); 
                regular_bg.get()->set_position(bn::fixed(0), bn::fixed(0)); 

                credits.init();
            }
            break;
        case GameState::GAMESTATE_INGAME:
            {
                bn::fixed_point ingame_center_offset(0,40);

                regular_bg.reset();

                affine_bg.reset();
                affine_bg = bn::affine_bg_items::map0.create_bg(0,0);
                affine_bg.get()->set_priority(3);
                affine_bg.get()->set_wrapping_enabled(false);    
                affine_bg.get()->set_position(ingame_center_offset);

                ingame.init(ingame_center_offset);
            }
            break;
        default:
            break;
    }
}
