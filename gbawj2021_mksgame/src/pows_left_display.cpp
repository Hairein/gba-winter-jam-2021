#include "pows_left_display.h"

namespace mks
{
    PowsLeftDisplay::PowsLeftDisplay()
        : MultiUiElement(3)
    {
    }

    PowsLeftDisplay::~PowsLeftDisplay()
    {
    }

    void PowsLeftDisplay::init(int pows_left)
    {   
        MultiUiElement::init();  

        set_sprite(0, bn::sprite_items::pows_left_icon.create_sprite_optional(70,-71));
        set_z_order(0, 0);

        update_pows_left_number(pows_left);
    }

    void PowsLeftDisplay::shutdown()
    {
        MultiUiElement::shutdown();     
    }

    void PowsLeftDisplay::update(int pows_left)
    {
        MultiUiElement::update(); 

        if(last_pows_left_value != pows_left)
        {
            update_pows_left_number(pows_left);
        }
    }

    void PowsLeftDisplay::update_pows_left_number(int pows_left)
    {
        int offset0 = pows_left / 10;
        int offset1 = pows_left % 10;

        set_sprite(1, bn::sprite_items::score_numbers1.create_sprite_optional(bn::fixed_point(80,-71),offset0));
        set_z_order(1, 0);
        set_sprite(2, bn::sprite_items::score_numbers1.create_sprite_optional(bn::fixed_point(88,-71),offset1));
        set_z_order(2, 0);

        last_pows_left_value = pows_left; 
    }
}