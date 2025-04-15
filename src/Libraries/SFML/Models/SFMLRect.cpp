/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SFMLRect.cpp
*/

#include "SFMLRect.hpp"
#include "Color.hpp"
#include "Vector.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

namespace Arc {

void SFMLRect::setSize(const Shared::Vector &size)
{
    this->_rectangle.setSize({size.getX(), size.getY()});
}

Shared::Vector SFMLRect::getSize() const
{
    sf::Vector2f vector = this->_rectangle.getSize();

    return {vector.x, vector.y};
}

void SFMLRect::setPos(const Shared::Vector &pos)
{
    this->_rectangle.setPosition({pos.getX(), pos.getY()});
}

Shared::Vector SFMLRect::getPos() const
{
    sf::Vector2f vector = this->_rectangle.getPosition();

    return {vector.y, vector.y};
}

void SFMLRect::setColor(const struct Shared::Color &color)
{
    this->_rectangle.setFillColor({static_cast<sf::Uint8>(color.R), static_cast<sf::Uint8>(color.G),
        static_cast<sf::Uint8>(color.B), static_cast<sf::Uint8>(color.A)});
}

struct Shared::Color& SFMLRect::getColor() const
{
    sf::Color sfColor = this->_rectangle.getFillColor();
    _color.A = sfColor.a;
    _color.R = sfColor.r;
    _color.G = sfColor.g;
    _color.B = sfColor.b;
    return _color;
}

void SFMLRect::setOutlineColor(const struct Shared::Color &color)
{
    this->_rectangle.setOutlineColor({static_cast<sf::Uint8>(color.R), static_cast<sf::Uint8>(color.G),
        static_cast<sf::Uint8>(color.B), static_cast<sf::Uint8>(color.A)});
}

Shared::Color& SFMLRect::getOutlineColor() const
{
    sf::Color sfColor = this->_rectangle.getOutlineColor();
    this->_outlineColor.A = sfColor.a;
    this->_outlineColor.R = sfColor.r;
    this->_outlineColor.G = sfColor.g;
    this->_outlineColor.B = sfColor.b;
    return this->_outlineColor;
}

void SFMLRect::setThickness(int thickness)
{
    this->_rectangle.setOutlineThickness(thickness);
}

int SFMLRect::getThickness() const
{
    return this->_rectangle.getOutlineThickness();
}

const sf::RectangleShape& SFMLRect::getRectangle() const
{
    return this->_rectangle;
}
}
