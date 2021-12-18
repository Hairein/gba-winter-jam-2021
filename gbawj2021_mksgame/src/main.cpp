#include <memory>

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
    std::unique_ptr<mks::Credits>& credits,
    std::unique_ptr<mks::Ingame>& ingame,
    std::unique_ptr<mks::StartGame>& start_game,
    std::unique_ptr<mks::Settings>& settings,
    std::unique_ptr<mks::Title>& title);

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

    std::unique_ptr<mks::Credits> credits;
    std::unique_ptr<mks::Ingame> ingame;
    std::unique_ptr<mks::StartGame> start_game;
    std::unique_ptr<mks::Settings> settings;
    std::unique_ptr<mks::Title> title;

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
                    credits.get()->update();

                    if(credits.get()->change_game_state() != GameState::GAMESTATE_NONE)
                    {
                        move_to_game_state(credits.get()->change_game_state(), 
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
                    ingame.get()->update();

                    if(ingame.get()->change_game_state() != GameState::GAMESTATE_NONE)
                    {
                        move_to_game_state(ingame.get()->change_game_state(), 
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
                        main_affine_bg.get()->set_pivot_position(ingame.get()->get_map_position());
                        main_affine_bg.get()->set_rotation_angle(ingame.get()->get_map_yaw());
                    }
                }
                break;
            case GameState::GAMESTATE_START_GAME:
                {
                    start_game.get()->update();

                    if(start_game.get()->change_game_state() != GameState::GAMESTATE_NONE)
                    {
                        move_to_game_state(start_game.get()->change_game_state(), 
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
                    settings.get()->update();

                    if(settings.get()->change_game_state() != GameState::GAMESTATE_NONE)
                    {
                        move_to_game_state(settings.get()->change_game_state(), 
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
                    title.get()->update();

                    if(title.get()->change_game_state() != GameState::GAMESTATE_NONE)
                    {
                        move_to_game_state(title.get()->change_game_state(), 
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
    std::unique_ptr<mks::Credits>& credits,
    std::unique_ptr<mks::Ingame>& ingame,
    std::unique_ptr<mks::StartGame>& start_game,
    std::unique_ptr<mks::Settings>& settings,
    std::unique_ptr<mks::Title>& title)
{
    previous_game_state = current_game_state;
    switch(previous_game_state)
    {
        case GameState::GAMESTATE_TITLE:
            {
                affine_bg.reset();
                
                regular_bg.reset();

                title.get()->shutdown();
                title.reset();
            }
            break;
        case GameState::GAMESTATE_START_GAME:
            {
                affine_bg.reset();
                
                regular_bg.reset();

                start_game.get()->shutdown();
                start_game.reset();
            }
            break;
        case GameState::GAMESTATE_SETTINGS:
            {
                affine_bg.reset();
                
                regular_bg.reset();

                settings.get()->shutdown();
                settings.reset();
            }
            break;
        case GameState::GAMESTATE_CREDITS:
            {
                affine_bg.reset();
                
                regular_bg.reset();

                credits.get()->shutdown();
                credits.reset();
            }
            break;
        case GameState::GAMESTATE_INGAME:
            {
                regular_bg.reset();

                affine_bg.reset();

                ingame.get()->shutdown();
                ingame.reset();
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

                title.reset(new mks::Title());
                title.get()->init();
            }
            break;
        case GameState::GAMESTATE_START_GAME:
            {
                affine_bg.reset();
                
                regular_bg.reset();
                regular_bg = bn::regular_bg_items::map_view.create_bg(0,0);
                regular_bg.get()->set_priority(3); 
                regular_bg.get()->set_position(bn::fixed(0), bn::fixed(0)); 

                start_game.reset(new mks::StartGame());
                start_game.get()->init();
            }
            break;
        case GameState::GAMESTATE_SETTINGS:
            {
                affine_bg.reset();
                
                regular_bg.reset();
                regular_bg = bn::regular_bg_items::map_view.create_bg(0,0);
                regular_bg.get()->set_priority(3); 
                regular_bg.get()->set_position(bn::fixed(0), bn::fixed(0)); 

                settings.reset(new mks::Settings());
                settings.get()->init();
            }
            break;
        case GameState::GAMESTATE_CREDITS:
            {
                affine_bg.reset();
                
                regular_bg.reset();
                regular_bg = bn::regular_bg_items::credits.create_bg(0,0);
                regular_bg.get()->set_priority(3); 
                regular_bg.get()->set_position(bn::fixed(0), bn::fixed(0)); 

                credits.reset(new mks::Credits());
                credits.get()->init();
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

                ingame.reset(new mks::Ingame());
                ingame.get()->init(ingame_center_offset);
            }
            break;
        default:
            break;
    }
}
