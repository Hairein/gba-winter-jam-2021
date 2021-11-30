#include "bn_core.h"
#include "bn_string.h"
#include "bn_keypad.h"
#include "bn_optional.h"
#include "bn_bg_palettes.h"
#include "bn_sprite_text_generator.h"
#include "bn_random.h"

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
    
    bn::vector<bn::sprite_ptr, 32> text_sprites;
    
    int counter = 0;
    int max_counter = 60;

    bn::random random_generator;
    int random_range = 101;

    while(true)
    {
        if(counter == 0)
        {
            //int random_value = random_generator.get() % random_range;
            unsigned int random_value = random_generator.get();

            bn::string<32> text;
            bn::ostringstream text_stream(text);
            text_stream.append(random_value);

            bn::string<32> text1;
            bn::ostringstream text_stream1(text1);
            text_stream1.append((random_value % random_range));
            text_stream1.append("%");

            text_sprites.clear();

            text_generator.generate(0, 0, text, text_sprites);
            text_generator.generate(0, 10, text1, text_sprites);
        }
        
        counter++;
        while(counter >= max_counter)
        {
            counter -= max_counter;
        }

        info.update();

        bn::core::update();
    }
}
