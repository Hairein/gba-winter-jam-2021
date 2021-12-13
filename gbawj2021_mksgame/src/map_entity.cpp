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

    void MapEntity::update(bn::fixed_point map_center, bn::fixed map_yaw_angle)
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
        sprite.get()->set_position(new_map_position);
    }

    bn::fixed_point MapEntity::get_map_position()
    {
        return sprite.get()->position();
    }

    void MapEntity::set_map_angle(bn::fixed new_angle)
    {
        sprite.get()->set_rotation_angle(new_angle);
    }

    bn::fixed MapEntity::get_map_angle()
    {
        return sprite.get()->rotation_angle();
    }
}