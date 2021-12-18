#include "ui_element.h"

namespace mks
{
    UiElement::UiElement()
    {
        active = false;
    }

    UiElement::~UiElement()
    {
    }
        
    void UiElement::init()
    {        
        active = true;
    }

    void UiElement::shutdown()
    {
        active = false;
        sprite.reset();
    }

    void UiElement::update()
    {
    }

    bool UiElement::is_active()
    {
        return active;
    }

    void UiElement::set_sprite(bn::optional<bn::sprite_ptr> new_sprite)
    {
        sprite.reset();
        sprite = new_sprite;
    }

    bn::optional<bn::sprite_ptr> UiElement::get_sprite()
    {
        return sprite;
    }

    void UiElement::set_position(bn::fixed_point& new_position)
    {
        sprite.get()->set_position(new_position);
    }

    bn::fixed_point UiElement::get_position()
    {
        return sprite.get()->position();
    }

    void UiElement::set_angle(bn::fixed& new_angle)
    {
        sprite.get()->set_rotation_angle(new_angle);
    }

    bn::fixed UiElement::get_angle()
    {
        return sprite.get()->rotation_angle();
    }

    void UiElement::set_z_order(int order)
    {
        sprite.get()->set_z_order(order);
    }

    int UiElement::get_z_order()
    {
        return sprite.get()->z_order();
    }
}