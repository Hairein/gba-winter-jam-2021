#include "player_shot.h"

namespace mks
{
    PlayerShot::PlayerShot()
    {
    }

    PlayerShot::~PlayerShot()
    {
    }
        
    void PlayerShot::init(bn::fixed_point& new_position, bn::fixed& new_angle)
    {
        MapEntity::init();

        sprite_index = 0;
        frame_hold_counter = 0;

        position = new_position;
        angle = new_angle;

        lifetime = SHOT_LIFETIME;
    }

    void PlayerShot::shutdown()
    {
        MapEntity::shutdown();
    }

    void PlayerShot::update(std::unique_ptr<VectorHelper>& vector_helper, std::unique_ptr<HitHandler>& hit_handler, bn::fixed_point& map_center, bn::fixed& map_yaw)
    {
        MapEntity::update();

        if(!is_active())
        {
            return;
        }

        if(lifetime <= 0)
        {
            hit_handler.get()->spawn(position, angle);
            
            shutdown();
            return;
        }

        if(sprite_index >= SHOT_SEQUENCE_MAX)
        {
            sprite_index -= SHOT_SEQUENCE_MAX;
        }

        bn::fixed_point new_sprite_position;
        bn::fixed new_sprite_rotation;
        vector_helper.get()->calculate_sprite_position_angle(map_center, map_yaw, position, angle, new_sprite_position, new_sprite_rotation);

        if(frame_hold_counter >= SHORT_FRAME_HOLD)
        {
            set_sprite(bn::sprite_items::shot_blue.create_sprite_optional(new_sprite_position.x(),new_sprite_position.y(),sprite_index));
            sprite.get()->set_z_order(2);
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

        lifetime--;

        bn::fixed_point direction = vector_helper.get()->get_rotated_unit_vector_y(angle.floor_integer());
        direction *= bn::fixed(SHOT_VELOCITY);
        position += direction;
    }
}