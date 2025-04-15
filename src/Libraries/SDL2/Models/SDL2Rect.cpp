/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SDL2Rect.cpp
*/

#include "SDL2Rect.hpp"

namespace Arc {

SDL2Rect::SDL2Rect(): _size(100, 100), _pos(0, 0), _thickness(0), _rect({0, 0, 0, 0}),
    _color(255, 255, 255, 255),
    _outlineColor({255, 255, 255, 255})
{
    this->_rect.setPos(this->_pos.getX(), this->_pos.getY());
    this->_rect.setSize(this->_size.getX(), this->_size.getY());
    this->_rect.setFillColor(this->_color);
    this->_rect.setOutlineColor(this->_outlineColor);
    this->_rect.setThickness(this->_thickness);
}

void SDL2Rect::setSize(const Shared::Vector &size)
{
    this->_rect.setSize(size.getX(), size.getY());
}

Shared::Vector SDL2Rect::getSize() const
{
    return this->_size;
}

void SDL2Rect::setPos(const Shared::Vector &pos)
{
    this->_rect.setPos(pos.getX(), pos.getY());
    this->_pos = pos;
}

Shared::Vector SDL2Rect::getPos() const
{
    return this->_pos;
}

void SDL2Rect::setColor(const struct Shared::Color &color)
{
    this->_color = color;
    this->_rect.setFillColor(this->_color);
}

struct Shared::Color &SDL2Rect::getColor() const
{
    return this->_color;
}

void SDL2Rect::setOutlineColor(const struct Shared::Color &color)
{
    this->_outlineColor = color;
    this->_rect.setOutlineColor(this->_outlineColor);
}

struct Shared::Color &SDL2Rect::getOutlineColor() const
{
    return this->_outlineColor;
}

void SDL2Rect::setThickness(int thickness)
{
    this->_rect.setThickness(thickness);
}

int SDL2Rect::getThickness() const
{
    return this->_thickness;
}

void SDL2Rect::draw(SDL2Renderer &renderer) const
{
    this->_rect.draw(renderer);
}
}
