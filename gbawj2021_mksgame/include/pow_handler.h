#ifndef MKS_POW_HANDLER_H
#define MKS_POW_HANDLER_H

#include "bn_core.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_vector.h"

#include "globals.h"
#include "pow.h"
#include "vector_helper.h"

namespace mks
{
    class PowHandler
    {
    public: 
        PowHandler();
        ~PowHandler();
        
        void init();
        void shutdown();
        void update(VectorHelper& vector_helper, bn::fixed_point& map_center, bn::fixed& map_yaw);
       
        bool spawn_pow(bn::fixed_point map_position, bn::fixed map_angle);

    protected:
        bn::vector<Pow,DEFAULT_SPRITE_VECTOR_SIZE> pows;
    };
}

#endif