#ifndef MKS_RTB_MESSAGE_DISPLAY_H
#define MKS_RTB_MESSAGE_DISPLAY_H

#include "bn_core.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"

#include "bn_sprite_items_rtb_message.h"

#include "globals.h"
#include "ui_element.h"

namespace mks
{
    class RtbMessageDisplay : public UiElement
    {
    public: 
        RtbMessageDisplay();
        ~RtbMessageDisplay();
        
        void init();
        void shutdown();
        void update(bool enable_show_message);

    protected:
        int flash_counter = 0;
        bool show_message;
    };
}

#endif