#ifndef MKS_GAME_H
#define MKS_GAME_H

#include "bn_regular_bg_ptr.h"

namespace mks
{
    class Game
    {
    public:
        Game();
        ~Game();

        void init();
        void update();
        void render(bn::sprite_text_generator& text_generator);
    };
}

#endif