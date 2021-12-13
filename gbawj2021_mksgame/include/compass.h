#ifndef MKS_COMPASS_H
#define MKS_COMPASS_H

#include "bn_core.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"

#include "globals.h"
#include "ui_element.h"

namespace mks
{
    class Compass : public UiElement
    {
    public: 
        Compass();
        ~Compass();
    };
}

#endif