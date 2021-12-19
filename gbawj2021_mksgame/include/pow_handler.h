#ifndef MKS_POW_HANDLER_H
#define MKS_POW_HANDLER_H

#include <memory.h>
#include <vector>

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
        void update(std::unique_ptr<VectorHelper>& vector_helper, bn::fixed_point& map_center, bn::fixed& map_yaw);
       
        bool spawn(bn::fixed_point& map_position, bn::fixed& map_angle);

    protected:
        std::vector<Pow> pows;
    };
}

#endif