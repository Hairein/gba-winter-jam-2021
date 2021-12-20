#include "multi_map_entity.h"

namespace mks
{
    MultiMapEntity::MultiMapEntity(size_t size)
    {
        active = false;

        for(size_t index = 0; index < size; index++)
        {
            bn::optional<bn::sprite_ptr> new_sprite;
            sprites.push_back(new_sprite);

            positions.push_back(bn::fixed_point(0,0));
            angles.push_back(bn::fixed(0));
        }
    }

    MultiMapEntity::~MultiMapEntity()
    {
    }
        
    void MultiMapEntity::init()
    {        
        active = true;
    }

    void MultiMapEntity::shutdown()
    {
        active = false;
        
        for(int index = 0; index < sprites.size(); index++)
        {
            sprites[index].reset();
        }
    }

    void MultiMapEntity::update()
    {
    }

    bool MultiMapEntity::is_active()
    {
        return active;
    }

    void MultiMapEntity::set_sprite(int index, bn::optional<bn::sprite_ptr> new_sprite)
    {
        sprites[index].reset();
        sprites[index] = new_sprite;
    }

    bn::optional<bn::sprite_ptr> MultiMapEntity::get_sprite(int index)
    {
        return sprites[index];
    }

    void MultiMapEntity::set_map_position(int index, bn::fixed_point& new_map_position)
    {
        positions[index] = new_map_position;
    }

    bn::fixed_point MultiMapEntity::get_map_position(int index)
    {
        return positions[index];
    }

    void MultiMapEntity::set_map_angle(int index, bn::fixed& new_angle)
    {
        angles[index] = new_angle;
    }

    bn::fixed MultiMapEntity::get_map_angle(int index)
    {
        return angles[index];
    }

    void MultiMapEntity::set_z_order(int index, int order)
    {
        sprites[index].get()->set_z_order(order);
    }

    int MultiMapEntity::get_z_order(int index)
    {
        return sprites[index].get()->z_order();
    }
}