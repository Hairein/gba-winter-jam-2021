#include "map_entity.h"

namespace mks
{
    MapEntity::MapEntity()
    {
        active = false;
    }

    MapEntity::~MapEntity()
    {
    }
        
    void MapEntity::init()
    {        
        active = true;
    }

    void MapEntity::shutdown()
    {
        active = false;
        sprite.reset();
    }

    void MapEntity::update()
    {
    }

    bool MapEntity::is_active()
    {
        return active;
    }

    void MapEntity::set_sprite(bn::optional<bn::sprite_ptr> new_sprite)
    {
        sprite.reset();
        sprite = new_sprite;
    }

    bn::optional<bn::sprite_ptr> MapEntity::get_sprite()
    {
        return sprite;
    }

    void MapEntity::set_map_position(bn::fixed_point new_map_position)
    {
        position = new_map_position;
    }

    bn::fixed_point MapEntity::get_map_position()
    {
        return position;
    }

    void MapEntity::set_map_angle(bn::fixed new_angle)
    {
        angle = new_angle;
    }

    bn::fixed MapEntity::get_map_angle()
    {
        return angle;
    }

    void MapEntity::set_z_order(int order)
    {
        sprite.get()->set_z_order(order);
    }

    int MapEntity::get_z_order()
    {
        return sprite.get()->z_order();
    }
}