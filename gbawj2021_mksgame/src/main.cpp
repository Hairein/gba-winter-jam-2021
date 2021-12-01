#include "bn_core.h"
#include "bn_sprite_text_generator.h"
#include "bn_bg_palettes.h"
#include "bn_fixed_point.h"
#include "bn_string.h"

#include "common_info.h"
#include "common_variable_8x16_sprite_font.h"

#include "bn_regular_bg_items_test_pattern.h"
#include "bn_regular_bg_items_layout.h"

#include "Game.h"

int main()
{
    bn::core::init();

    bn::sprite_text_generator text_generator(common::variable_8x16_sprite_font);
    bn::bg_palettes::set_transparent_color(bn::color(2, 2, 2));

    constexpr bn::string_view info_text_lines[] = {
        "Test"
    };

    common::info info("MKS Game", info_text_lines, text_generator);

    auto test_pattern_bg = bn::regular_bg_items::test_pattern.create_bg(0,0);
    //auto layout_bg = bn::regular_bg_items::layout.create_bg(64,0);

    while(true)
    {
        info.update();

        bn::core::update();
    }
}
