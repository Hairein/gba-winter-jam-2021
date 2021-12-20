#ifndef MKS_MAPHELPER_H
#define MKS_MAPHELPER_H

#include "bn_fixed.h"
#include "bn_fixed_point.h"

#include "globals.h"

namespace mks
{
    class MapHelper
    {
    public:
        MapHelper();
        ~MapHelper();
        
        void find_player_start_position(bn::fixed_point& map_position);
        
        void get_map_tile(int tile_x, int tile_y, int& found_tile);
        void get_map_tile_from_map_position(int pixel_x, int pixel_y, int& found_tile);
        void count_map_tiles(int tile_type, int& nos);
    };
}

#endif