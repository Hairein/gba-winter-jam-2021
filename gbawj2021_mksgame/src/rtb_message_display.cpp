#include "ingame.h"

#include "rtb_message_display.h"

namespace mks
{
    RtbMessageDisplay::RtbMessageDisplay(Ingame* ingame_ptr)
    {
        ingame = ingame_ptr;

        active = false;
    }

    RtbMessageDisplay::~RtbMessageDisplay()
    {
    }
        
    void RtbMessageDisplay::init()
    {   
        UiElement::init(); 

        flash_counter = FLASH_COUNTER_MAX;   
        show_message = false;
    }

    void RtbMessageDisplay::shutdown()
    {
        UiElement::shutdown();     
    }

    void RtbMessageDisplay::update(bool enable_show_message)
    {
        UiElement::update(); 

        flash_counter++;
        if(flash_counter >= FLASH_COUNTER_MAX)
        {
            flash_counter = 0;

            show_message = !show_message;

            sprite.reset();         
            if(show_message && enable_show_message)
            {
                set_sprite(bn::sprite_items::rtb_message.create_sprite_optional(0, 76, 0));
                set_z_order(0);
            }
        }  
    }
}