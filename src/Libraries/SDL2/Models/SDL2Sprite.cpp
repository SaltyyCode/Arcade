/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SDL2Sprite.cpp
*/

#include "SDL2Sprite.hpp"
#include "Vector.hpp"
#include <SDL2/SDL_rect.h>
#include <memory>

namespace Arc {

SDL2Sprite::SDL2Sprite(std::shared_ptr<SDL2Texture> texture): _texture(texture),
    _origin(0, 0),
    _rect(0, 0, 0, 0),
    _textRect(0, 0, 0 ,0),
    _rotation(0.f),
    _color(255, 255, 255, 255),
    _scale(1.f, 1.f)
{
    SDL2::getTextureSize(*this->_texture, this->_rect);
    SDL2::getTextureSize(*this->_texture, this->_textRect);
}

void SDL2Sprite::setSize(const Shared::Vector& size)
{
    this->_rect.w = size.getX();
    this->_rect.h = size.getY();
}

Shared::Vector SDL2Sprite::getSize() const
{
    return {static_cast<float>(this->_rect.w), static_cast<float>(this->_rect.h)};
}

void SDL2Sprite::setPos(const Shared::Vector &pos)
{
    this->_rect.x = pos.getX();
    this->_rect.y = pos.getY();
}

Shared::Vector SDL2Sprite::getPos() const
{
    return {static_cast<float>(this->_rect.x), static_cast<float>(this->_rect.y)};
}

void SDL2Sprite::setRectPos(const Shared::Vector &pos)
{
    this->_textRect.x = pos.getX();
    this->_textRect.y = pos.getY();
}

Shared::Vector SDL2Sprite::getRectPos() const
{
    return {static_cast<float>(this->_textRect.x), static_cast<float>(this->_textRect.y)};
}

void SDL2Sprite::setRectSize(const Shared::Vector &size)
{
    this->_textRect.w = size.getX();
    this->_textRect.h = size.getY();
}

Shared::Vector SDL2Sprite::getRectSize() const
{
    return {static_cast<float>(this->_textRect.w), static_cast<float>(this->_textRect.h)};
}

void SDL2Sprite::setRotation(float rotation)
{
    this->_rotation = rotation;
}

void SDL2Sprite::setScale(const Shared::Vector &scale)
{
    this->_scale = scale;
}

Shared::Vector SDL2Sprite::getScale() const
{
    return this->_scale;
}

float SDL2Sprite::getRotation() const
{
    return this->_rotation;
}

void SDL2Sprite::setOrigin(const Shared::Vector &origin)
{
    this->_origin = origin;
}

Shared::Vector SDL2Sprite::getOrigin() const
{
    return this->_origin;
}

void SDL2Sprite::setColor(const Shared::Color &color)
{
    this->_color = color;
}

Shared::Color SDL2Sprite::getColor() const
{
    return this->_color;
}

void SDL2Sprite::draw(SDL2Renderer &renderer) const
{
    SDL_Point center = {static_cast<int>(this->_origin.getX()), static_cast<int>(this->_origin.getY())};
    SDL_Rect dstRect = this->_rect;
    dstRect.w *= this->_scale.getX();
    dstRect.h *= this->_scale.getY();

    SDL2::renderCopyEx(renderer, *this->_texture, &this->_textRect, &dstRect, this->_rotation, &center);
}
}
