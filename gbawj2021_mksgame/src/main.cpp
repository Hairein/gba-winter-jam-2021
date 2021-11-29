#include "bn_core.h"
#include "bn_string.h"
#include "bn_keypad.h"
#include "bn_optional.h"
#include "bn_bg_palettes.h"
#include "bn_sprite_text_generator.h"

#include "common_info.h"
#include "common_variable_8x16_sprite_font.h"

int main()
{
    bn::core::init();

    bn::sprite_text_generator text_generator(common::variable_8x16_sprite_font);
    bn::bg_palettes::set_transparent_color(bn::color(2, 2, 2));

    constexpr bn::string_view info_text_lines[] = {
        "Hello, World!",
    };

    common::info info("Hi there", info_text_lines, text_generator);
    
    while(true)
    {
        info.update();

        bn::core::update();
    }
}
