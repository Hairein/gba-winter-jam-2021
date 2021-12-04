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

#include "Game.h"

enum GameState 
{
    NONE, 
    START, 
    TITLE,
    SETTINGS,
    CREDITS,
    INGAME
};

int main();
void move_to_game_state(GameState new_game_state, 
    GameState& previous_game_state, 
    GameState& current_game_state,
    bn::optional<bn::affine_bg_ptr>& affine_bg,
    bn::optional<bn::regular_bg_ptr>& regular_bg,
    bn::fixed_point& player_position,
    bn::fixed& player_yaw_rotation);

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

    bn::fixed_point player_position(0, 0);
    bn::fixed player_yaw_rotation = 0;

    mks::Game game;

    GameState previous_game_state = GameState::NONE;
    GameState current_game_state = GameState::NONE;

    move_to_game_state(GameState::TITLE, 
        previous_game_state, 
        current_game_state, 
        main_bg, 
        overlay_bg,
        player_position, 
        player_yaw_rotation);

    while(true)
    {
        switch(current_game_state)
        {
            case GameState::TITLE:
                {
                    if(bn::keypad::start_released())
                    {
                        move_to_game_state(GameState::INGAME, 
                            previous_game_state, 
                            current_game_state, 
                            main_bg, 
                            overlay_bg,
                            player_position, 
                            player_yaw_rotation);
                    }
                }
                break;
            case GameState::INGAME:
                {
                    game.handle_player_navigation(player_position, player_yaw_rotation);

                    main_bg.get()->set_pivot_position(player_position);
                    main_bg.get()->set_rotation_angle(player_yaw_rotation);

                    if(game.quit())
                    {
                        move_to_game_state(GameState::TITLE, 
                            previous_game_state, 
                            current_game_state, 
                            main_bg, 
                            overlay_bg,
                            player_position, 
                            player_yaw_rotation);
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
    bn::fixed_point& player_position,
    bn::fixed& player_yaw_rotation)
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
        case GameState::TITLE:
            {
                affine_bg.reset();
                
                regular_bg.reset();
                regular_bg = bn::regular_bg_items::layout.create_bg(0,0);
                regular_bg.get()->set_priority(0); 
                regular_bg.get()->set_position(bn::fixed(0), bn::fixed(0)); 
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

                player_position.set_x(0);
                player_position.set_y(0);
                player_yaw_rotation = 0;
            }
            break;
        default:
            break;
    }
}
