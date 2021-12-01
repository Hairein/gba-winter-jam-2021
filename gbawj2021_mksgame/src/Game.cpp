#include "bn_fixed_point.h"
#include "bn_string.h"
#include "bn_sprite_text_generator.h"


#include "bn_regular_bg_items_test_pattern.h"
#include "bn_regular_bg_items_layout.h"

#include "Game.h"

namespace mks
{
    Game::Game()
    {
    }

    Game::~Game()
    {
    }

    void Game::init()
    {
        auto test_pattern_bg = bn::regular_bg_items::test_pattern.create_bg(bn::fixed_point(0,0));
        test_pattern_bg.set_visible(true);
    }

    void Game::update()
    {
    }

    void Game::render(bn::sprite_text_generator& text_generator)
    {
    }
}