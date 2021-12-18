#ifndef MKS_CRATER_HANDLER_H
#define MKS_CRATER_HANDLER_H

#include "bn_core.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_vector.h"

#include "globals.h"
#include "crater.h"
#include "vector_helper.h"

namespace mks
{
    class CraterHandler
    {
    public: 
        CraterHandler();
        ~CraterHandler();
        
        void init();
        void shutdown();
        void update(VectorHelper& vector_helper, bn::fixed_point& map_center, bn::fixed& map_yaw);
       
        bool spawn(bn::random& random, bn::fixed_point& map_position);

    protected:
        bn::vector<Crater,DEFAULT_SPRITE_VECTOR_SIZE> craters;
    };
}

#endif