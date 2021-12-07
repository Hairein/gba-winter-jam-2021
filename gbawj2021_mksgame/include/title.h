#ifndef MKS_TITLE_H
#define MKS_TITLE_H

#include "bn_core.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"

#include "globals.h"

namespace mks
{
    class Title
    {
    public: 
        Title();
        ~Title();
        
        void init();
        void shutdown();
        void update();

        GameState change_game_state();
    
    protected:
        GameState next_game_state;

        bn::optional<bn::sprite_ptr> text_main_menu_version;
        bn::optional<bn::sprite_ptr> button_a_sprite;
        bn::optional<bn::sprite_ptr> button_main_menu_start_sprite;
        bn::optional<bn::sprite_ptr> button_main_menu_settings_sprite;
        bn::optional<bn::sprite_ptr> button_main_menu_credits_sprite;

        int menu_index = 0;

        void update_cursor();
    };
}

#endif