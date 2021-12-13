#ifndef MKS_ANIMATED_MAP_ENTITY_H
#define MKS_ANIMATED_MAP_ENTITY_H

#include "bn_core.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_vector.h"

#include "globals.h"
#include "map_entity.h"

namespace mks
{
    class AnimatedMapEntity : public MapEntity
    {
    public: 
        AnimatedMapEntity();
        ~AnimatedMapEntity();
                
    protected:
    };
}

#endif