#include "multi_ui_element.h"

namespace mks
{
    MultiUiElement::MultiUiElement(int size)
    {
        active = false;

        for(int index = 0; index < size; index++)
        {
            bn::optional<bn::sprite_ptr> new_sprite;
            sprites.push_back(new_sprite);
        }
    }

    MultiUiElement::~MultiUiElement()
    {
    }
        
    void MultiUiElement::init()
    {        
        active = true;
    }

    void MultiUiElement::shutdown()
    {
        active = false;

        for(int index = 0; index < sprites.size(); index++)
        {
            sprites[index].reset();
        }
    }

    void MultiUiElement::update()
    {
    }

    bool MultiUiElement::is_active()
    {
        return active;
    }

    void MultiUiElement::set_sprite(int index, bn::optional<bn::sprite_ptr> new_sprite)
    {
        sprites[index].reset();
        sprites[index] = new_sprite;
    }

    bn::optional<bn::sprite_ptr> MultiUiElement::get_sprite(int index)
    {
        return sprites[index];
    }

    void MultiUiElement::set_position(int index, bn::fixed_point& new_position)
    {
        sprites[index].get()->set_position(new_position);
    }

    bn::fixed_point MultiUiElement::get_position(int index)
    {
        return sprites[index].get()->position();
    }

    void MultiUiElement::set_angle(int index, bn::fixed& new_angle)
    {
        sprites[index].get()->set_rotation_angle(new_angle);
    }

    bn::fixed MultiUiElement::get_angle(int index)
    {
        return sprites[index].get()->rotation_angle();
    }

    void MultiUiElement::set_z_order(int index, int order)
    {
        sprites[index].get()->set_z_order(order);
    }

    int MultiUiElement::get_z_order(int index)
    {
        return sprites[index].get()->z_order();
    }
}