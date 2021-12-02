#include "bn_core.h"
#include "bn_sprite_text_generator.h"
#include "bn_bg_palettes.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_string.h"
#include "bn_optional.h"

#include "common_info.h"
#include "common_variable_8x16_sprite_font.h"

#include "bn_regular_bg_items_test_pattern2.h"
#include "bn_regular_bg_items_overlay_pattern.h"
#include "bn_regular_bg_items_world.h"

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

    bn::optional<bn::regular_bg_ptr> test_pattern_bg = bn::regular_bg_items::world.create_bg(0,0);
    test_pattern_bg.get()->set_priority(1);

    bn::optional<bn::regular_bg_ptr> overlay_pattern_bg = bn::regular_bg_items::overlay_pattern.create_bg(0,0);
    overlay_pattern_bg.get()->set_priority(0);

    bn::fixed offset = 0;

    while(true)
    {
        overlay_pattern_bg.get()->set_position(offset, 0);
        
        offset += bn::fixed(0.2);
        while(offset >= bn::fixed(256))
        {
            offset -= bn::fixed(256);
        }

        info.update();

        bn::core::update();
    }
}
