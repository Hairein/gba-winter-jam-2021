#include "dual_map_entity.h"

namespace mks
{
    DualMapEntity::DualMapEntity()
    {
        active = false;
    }

    DualMapEntity::~DualMapEntity()
    {
    }
        
    void DualMapEntity::init()
    {        
        active = true;
    }

    void DualMapEntity::shutdown()
    {
        active = false;
        
        sprite[0].reset();
        sprite[1].reset();
    }

    void DualMapEntity::update(bn::fixed_point map_center, bn::fixed map_yaw_angle)
    {
    }

    bool DualMapEntity::is_active()
    {
        return active;
    }

    void DualMapEntity::set_sprite(int index, bn::optional<bn::sprite_ptr> new_sprite)
    {
        sprite[index].reset();
        sprite[index] = new_sprite;
    }

    bn::optional<bn::sprite_ptr> DualMapEntity::get_sprite(int index)
    {
        return sprite[index];
    }

    void DualMapEntity::set_map_position(int index, bn::fixed_point new_map_position)
    {
        position[index] = new_map_position;
    }

    bn::fixed_point DualMapEntity::get_map_position(int index)
    {
        return position[index];
    }

    void DualMapEntity::set_map_angle(int index, bn::fixed new_angle)
    {
        angle[index] = new_angle;
    }

    bn::fixed DualMapEntity::get_map_angle(int index)
    {
        return angle[index];
    }
}