#ifndef MKS_POWS_LEFT_DISPLAY_H
#define MKS_POWS_LEFT_DISPLAY_H

#include "bn_core.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"

#include "bn_sprite_items_pows_left_icon.h"
#include "bn_sprite_items_score_numbers1.h"

#include "globals.h"
#include "multi_ui_element.h"

namespace mks
{
    class Ingame;

    class PowsLeftDisplay : public MultiUiElement
    {
    public: 
        PowsLeftDisplay(Ingame* ingame_ptr);
        ~PowsLeftDisplay();
        
        void init();
        void shutdown();
        void update(int pows_left);
    
    protected:
        Ingame* ingame;

        int last_pows_left_value;

        void update_pows_left_number(int pows_left);
    };
}

#endif