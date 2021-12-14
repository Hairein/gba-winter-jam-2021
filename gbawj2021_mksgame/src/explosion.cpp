#include "explosion.h"

namespace mks
{
    Explosion::Explosion()
    {
    }

    Explosion::~Explosion()
    {
    }
        
    void Explosion::init(bn::fixed_point& new_position, bn::fixed& new_angle)
    {
        MapEntity::init();

        sprite_index = 0;
        frame_hold_counter = 0;

        position = new_position;
        angle = new_angle;
    }

    void Explosion::shutdown()
    {
        MapEntity::shutdown();
    }

    void Explosion::update(VectorHelper& vector_helper, bn::fixed_point& map_center, bn::fixed& map_yaw)
    {
        MapEntity::update(map_center, map_yaw);

        if(!is_active())
        {
            return;
        }

        if(sprite_index >= 16)
        {
            shutdown();
            return;
        }

        auto unrotated_sprite_position = position - map_center;       
        auto raw_rotation =  -map_yaw;
        while(raw_rotation < bn::fixed(0)) raw_rotation += bn::fixed(360);
        while(raw_rotation >= bn::fixed(360)) raw_rotation -= bn::fixed(360);

        auto new_sprite_position = vector_helper.rotate_vector(unrotated_sprite_position, raw_rotation);
        
        auto new_sprite_rotation = map_yaw - angle;
        while(new_sprite_rotation < bn::fixed(0)) new_sprite_rotation += bn::fixed(360);
        while(new_sprite_rotation >= bn::fixed(360)) new_sprite_rotation -= bn::fixed(360);

        if(frame_hold_counter >= SHORT_FRAME_HOLD)
        {
            set_sprite(bn::sprite_items::explosion_sequence1.create_sprite_optional(new_sprite_position.x(),new_sprite_position.y(),sprite_index));
            sprite.get()->set_rotation_angle(new_sprite_rotation);

            sprite_index++;
            frame_hold_counter = 0;
        }
        else
        {
            sprite.get()->set_position(new_sprite_position);
            sprite.get()->set_rotation_angle(new_sprite_rotation);
            
            frame_hold_counter++;
        }
    }
}