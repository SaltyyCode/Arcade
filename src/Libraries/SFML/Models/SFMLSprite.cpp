/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SFMLSprite.cpp
*/

#include "SFMLSprite.hpp"
#include "Vector.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>

namespace Arc {

SFMLSprite::SFMLSprite(std::shared_ptr<sf::Texture> texture): _sprite(*texture), _texture(texture)
{
    this->_size.setX(texture->getSize().x);
    this->_size.setY(texture->getSize().y);
}

void SFMLSprite::updateSprite()
{
    sf::Vector2f _rect = {this->_sprite.getLocalBounds().width, this->_sprite.getLocalBounds().height};

    if (!_rect.x || !_rect.y)
        return;
    this->_sprite.setScale({(_size.getX() / _rect.x) * _scale.getX(),
        (_size.getY() / _rect.y) * _scale.getY()});
}

void SFMLSprite::setSize(const Shared::Vector &size)
{
    this->_size = size;
    this->updateSprite();
}

Shared::Vector SFMLSprite::getSize() const
{
    return this->_size;
}

void SFMLSprite::setPos(const Shared::Vector &pos)
{
    this->_sprite.setPosition({pos.getX(), pos.getY()});
}

Shared::Vector SFMLSprite::getPos() const
{
    sf::Vector2f pos = this->_sprite.getPosition();

    return {pos.x, pos.y};
}

void SFMLSprite::setRectPos(const Shared::Vector &pos)
{
    sf::IntRect _rect = this->_sprite.getTextureRect();

    _rect.left = static_cast<int>(pos.getX());
    _rect.top = static_cast<int>(pos.getY());
    this->_sprite.setTextureRect(_rect);
}

Shared::Vector SFMLSprite::getRectPos() const
{
    sf::IntRect _rect = this->_sprite.getTextureRect();

    return {static_cast<float>(_rect.left), static_cast<float>(_rect.top)};
}

void SFMLSprite::setRectSize(const Shared::Vector &size)
{
    sf::IntRect _rect = this->_sprite.getTextureRect();
    _rect.width = static_cast<int>(size.getX());
    _rect.height= static_cast<int>(size.getY());
    this->_sprite.setTextureRect(_rect);
    this->updateSprite();
}

Shared::Vector SFMLSprite::getRectSize() const
{
    sf::IntRect _rect = this->_sprite.getTextureRect();

    return {static_cast<float>(_rect.width), static_cast<float>(_rect.height)};
}

void SFMLSprite::setRotation(float)
{
}

float SFMLSprite::getRotation() const
{
    return 0.f;
}

void SFMLSprite::setScale(const Shared::Vector &scale)
{
    this->_scale = scale;
    this->updateSprite();
}

Shared::Vector SFMLSprite::getScale() const
{
    return this->_scale;
}

void SFMLSprite::setOrigin(const Shared::Vector &origin)
{
    this->_sprite.setOrigin({origin.getX(), origin.getY()});
}

Shared::Vector SFMLSprite::getOrigin() const
{
    sf::Vector2f origin = this->_sprite.getOrigin();

    return {origin.x, origin.y};
}

void SFMLSprite::setColor (const Shared::Color &color)
{
    sf::Color sfColor;

    sfColor.a = color.A;
    sfColor.r = color.R;
    sfColor.g = color.G;
    sfColor.b = color.B;
    this->_sprite.setColor(sfColor);
}

Shared::Color SFMLSprite::getColor() const
{
    sf::Color color = this->_sprite.getColor();

    return {color.r, color.g, color.b, color.a};
}

}
