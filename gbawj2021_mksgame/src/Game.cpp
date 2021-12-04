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
    }

    void Game::update(bn::optional<bn::affine_bg_ptr> main_bg)
    {
    }

    void Game::render(bn::sprite_text_generator text_generator, bn::optional<bn::affine_bg_ptr> main_bg)
    {
    }

    bn::fixed_point Game::getRotatedUnitVectorX(int angle)
    {
        return rotated_unit_vectors_x[angle];
    }

    bn::fixed_point Game::getRotatedUnitVectorY(int angle)
    {
        return rotated_unit_vectors_y[angle];
    }
}