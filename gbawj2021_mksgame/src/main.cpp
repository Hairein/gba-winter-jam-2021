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

#include "common_info.h"
#include "common_variable_8x16_sprite_font.h"

#include "bn_affine_bg_items_world.h"
#include "bn_regular_bg_items_layout.h"

#include "globals.h"

#include "continuegame.h"
#include "credits.h"
#include "ingame.h"
#include "newgame.h"
#include "settings.h"
#include "title.h"

int main();
void move_to_game_state(GameState new_game_state, 
    GameState& previous_game_state, 
    GameState& current_game_state,
    bn::optional<bn::affine_bg_ptr>& affine_bg,
    bn::optional<bn::regular_bg_ptr>& regular_bg,
    mks::ContinueGame& continue_game,
    mks::Credits& credits,
    mks::Ingame& ingame,
    mks::NewGame& new_game,
    mks::Settings& settings,
    mks::Title& title);

int main()
{
    bn::core::init();

    bn::sprite_text_generator text_generator(common::variable_8x16_sprite_font);
    bn::bg_palettes::set_transparent_color(bn::color(4, 4, 4));

    constexpr bn::string_view info_text_lines[] = {
        "*"
    };

    common::info info("Operation Terse", info_text_lines, text_generator);

    bn::optional<bn::affine_bg_ptr> main_bg;
    bn::optional<bn::regular_bg_ptr> overlay_bg;

    mks::ContinueGame continue_game;
    mks::Credits credits;
    mks::Ingame ingame;
    mks::NewGame new_game;
    mks::Settings settings;
    mks::Title title;

    GameState previous_game_state = GameState::NONE;
    GameState current_game_state = GameState::NONE;

    move_to_game_state(GameState::START, 
        previous_game_state, 
        current_game_state, 
        main_bg, 
        overlay_bg,
        continue_game,
        credits,
        ingame,
        new_game,
        settings,
        title);

    while(true)
    {
        switch(current_game_state)
        {
            case GameState::START: // One-time initialization
                {
                    move_to_game_state(GameState::TITLE, 
                        previous_game_state, 
                        current_game_state, 
                        main_bg, 
                        overlay_bg,
                        continue_game,
                        credits,
                        ingame,
                        new_game,
                        settings,
                        title);
                }
                break;
            case GameState::TITLE:
                {
                    title.update();

                    if(title.change_game_state() != GameState::NONE)
                    {
                        move_to_game_state(title.change_game_state(), 
                            previous_game_state, 
                            current_game_state, 
                            main_bg, 
                            overlay_bg,
                            continue_game,
                            credits,
                            ingame,
                            new_game,
                            settings,
                            title);
                    }
                    else
                    {
                    }
                }
                break;
            case GameState::INGAME:
                {
                    ingame.update();

                    if(ingame.change_game_state() != GameState::NONE)
                    {
                        move_to_game_state(ingame.change_game_state(), 
                            previous_game_state, 
                            current_game_state, 
                            main_bg, 
                            overlay_bg,
                            continue_game,
                            credits,
                            ingame,
                            new_game,
                            settings,
                            title);
                    }
                    else
                    {
                        main_bg.get()->set_pivot_position(ingame.get_player_position());
                        main_bg.get()->set_rotation_angle(ingame.get_player_yaw_rotation());
                    }
                }
                break;
            default:
                break;
        }

        // ---

        info.update();

        bn::core::update();
    }
}

void move_to_game_state(GameState new_game_state, 
    GameState& previous_game_state, 
    GameState& current_game_state,
    bn::optional<bn::affine_bg_ptr>& affine_bg,
    bn::optional<bn::regular_bg_ptr>& regular_bg,
    mks::ContinueGame& continue_game,
    mks::Credits& credits,
    mks::Ingame& ingame,
    mks::NewGame& new_game,
    mks::Settings& settings,
    mks::Title& title)
{
    previous_game_state = current_game_state;
    switch(previous_game_state)
    {
        default:
            break;
    }

    current_game_state = new_game_state;    
    switch(current_game_state)
    {
        case GameState::START:
            break;
        case GameState::TITLE:
            {
                affine_bg.reset();
                
                regular_bg.reset();
                regular_bg = bn::regular_bg_items::layout.create_bg(0,0);
                regular_bg.get()->set_priority(0); 
                regular_bg.get()->set_position(bn::fixed(0), bn::fixed(0)); 

                title.init();
            }
            break;
        case GameState::NEW_GAME:
            {
                affine_bg.reset();
                
                regular_bg.reset();
                regular_bg = bn::regular_bg_items::layout.create_bg(0,0);
                regular_bg.get()->set_priority(0); 
                regular_bg.get()->set_position(bn::fixed(0), bn::fixed(0)); 

                new_game.init();
            }
            break;
        case GameState::CONTINUE_GAME:
            {
                affine_bg.reset();
                
                regular_bg.reset();
                regular_bg = bn::regular_bg_items::layout.create_bg(0,0);
                regular_bg.get()->set_priority(0); 
                regular_bg.get()->set_position(bn::fixed(0), bn::fixed(0)); 

                continue_game.init();
            }
            break;
        case GameState::SETTINGS:
            {
                affine_bg.reset();
                
                regular_bg.reset();
                regular_bg = bn::regular_bg_items::layout.create_bg(0,0);
                regular_bg.get()->set_priority(0); 
                regular_bg.get()->set_position(bn::fixed(0), bn::fixed(0)); 

                settings.init();
            }
            break;
        case GameState::CREDITS:
            {
                affine_bg.reset();
                
                regular_bg.reset();
                regular_bg = bn::regular_bg_items::layout.create_bg(0,0);
                regular_bg.get()->set_priority(0); 
                regular_bg.get()->set_position(bn::fixed(0), bn::fixed(0)); 

                credits.init();
            }
            break;
        case GameState::INGAME:
            {
                regular_bg.reset();

                affine_bg.reset();
                affine_bg = bn::affine_bg_items::world.create_bg(0,0);
                affine_bg.get()->set_priority(1);
                affine_bg.get()->set_wrapping_enabled(false);    
                affine_bg.get()->set_position(bn::fixed(0), bn::fixed(40)); // screen center offset

                ingame.init();
            }
            break;
        default:
            break;
    }
}
