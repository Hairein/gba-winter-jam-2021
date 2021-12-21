#ifndef MKS_CRATER_HANDLER_H
#define MKS_CRATER_HANDLER_H

#include <memory.h>
#include <vector>

#include "bn_core.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_vector.h"

#include "globals.h"

namespace mks
{
    class Ingame;
    class Crater;
    
    class CraterHandler
    {
    public: 
        CraterHandler(Ingame* ingame_ptr);
        ~CraterHandler();
        
        void init();
        void shutdown();
        void update(bn::fixed_point calculated_map_center);
       
        bool spawn(bn::fixed_point& map_position);

    protected:
        Ingame* ingame;

        std::vector<Crater> craters;
    };
}

#endif