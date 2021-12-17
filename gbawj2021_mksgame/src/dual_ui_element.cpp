#include "dual_ui_element.h"

namespace mks
{
    DualUiElement::DualUiElement()
    {
        active = false;
    }

    DualUiElement::~DualUiElement()
    {
    }
        
    void DualUiElement::init()
    {        
        active = true;
    }

    void DualUiElement::shutdown()
    {
        active = false;
        sprite[0].reset();
        sprite[1].reset();
    }

    void DualUiElement::update()
    {
    }

    bool DualUiElement::is_active()
    {
        return active;
    }

    void DualUiElement::set_sprite(int index, bn::optional<bn::sprite_ptr> new_sprite)
    {
        sprite[index].reset();
        sprite[index] = new_sprite;
    }

    bn::optional<bn::sprite_ptr> DualUiElement::get_sprite(int index)
    {
        return sprite[index];
    }

    void DualUiElement::set_position(int index, bn::fixed_point new_position)
    {
        sprite[index].get()->set_position(new_position);
    }

    bn::fixed_point DualUiElement::get_position(int index)
    {
        return sprite[index].get()->position();
    }

    void DualUiElement::set_angle(int index, bn::fixed new_angle)
    {
        sprite[index].get()->set_rotation_angle(new_angle);
    }

    bn::fixed DualUiElement::get_angle(int index)
    {
        return sprite[index].get()->rotation_angle();
    }

    void DualUiElement::set_z_order(int index, int order)
    {
        sprite[index].get()->set_z_order(order);
    }

    int DualUiElement::get_z_order(int index)
    {
        return sprite[index].get()->z_order();
    }
}