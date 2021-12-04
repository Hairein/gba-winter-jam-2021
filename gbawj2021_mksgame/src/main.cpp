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
#include "bn_log.h"
#include "bn_span.h"

#include "common_info.h"
#include "common_variable_8x16_sprite_font.h"

#include "bn_affine_bg_items_world.h"

#include "Game.h"

int main()
{
    bn::core::init();

    bn::sprite_text_generator text_generator(common::variable_8x16_sprite_font);
    bn::bg_palettes::set_transparent_color(bn::color(4, 4, 4));

    constexpr bn::string_view info_text_lines[] = {
        "Test"
    };

    common::info info("MKS Game", info_text_lines, text_generator);

    bn::optional<bn::affine_bg_ptr> main_bg = bn::affine_bg_items::world.create_bg(0,0);
    main_bg.get()->set_priority(1);
    main_bg.get()->set_wrapping_enabled(false);    
    main_bg.get()->set_position(bn::fixed(), bn::fixed(40)); // screen center offset

    // bn::affine_bg_map_ptr bg_map = main_bg.get()->map();
    // auto cells = bg_map.cells_ref();
    // auto cells_ptr = cells.get()->data();
    // for(int index = 0; index < cells.get()->size();index++)
    // {
    //     //const bn::regular_bg_map_cell cell = cells.get()->at(index);
    //     //auto tile_index = cell.tile_index();
    //     //cell.set_tile_index(bn::regular_bg_map_cell(0));
    //     //*(cells_ptr + index) = bn::regular_bg_map_cell(1);
    // }

    bn::fixed angle = 0;

    bn::fixed offsetX = 100;
    bn::fixed offsetY = 100;

    mks::Game game;

    while(true)
    {
        if(bn::keypad::left_held())
        {
            angle -= bn::fixed(1);
        }
        else if(bn::keypad::right_held())
        {
            angle += bn::fixed(1);
        }

        while(angle >= bn::fixed(360))
        {
            angle -= bn::fixed(360);
        }
        while(angle < bn::fixed(0))
        {
            angle += bn::fixed(360);
        }

        // ---

        auto offsetUnitVectorX = game.getRotatedUnitVectorX(angle.floor_integer());
        auto offsetUnitVectorY = game.getRotatedUnitVectorY(angle.floor_integer());

        if(bn::keypad::a_held())
        {
            offsetX += offsetUnitVectorX.x();
            offsetY += offsetUnitVectorX.y();
        }
        else if(bn::keypad::b_held())
        {
            offsetX -= offsetUnitVectorX.x();
            offsetY -= offsetUnitVectorX.y();
        }

        if(bn::keypad::down_held())
        {
            offsetX -= offsetUnitVectorY.x();
            offsetY -= offsetUnitVectorY.y();
        }
        else if(bn::keypad::up_held())
        {
            offsetX += offsetUnitVectorY.x();
            offsetY += offsetUnitVectorY.y();
        }

        // ---

        main_bg.get()->set_pivot_position(offsetX, offsetY);
        main_bg.get()->set_rotation_angle(angle);

        // ---

        info.update();

        bn::core::update();
    }
}
