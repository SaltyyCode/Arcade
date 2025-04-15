/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SDL2Text.cpp
*/

#include "SDL2Text.hpp"
#include "Color.hpp"
#include "Vector.hpp"
#include <memory>
#include <string>

namespace Arc {

SDL2Text::SDL2Text(const std::string& path, std::shared_ptr<SDL2Renderer> &renderer, std::shared_ptr<SDL2TTF> &ttf): _ttf(ttf), _size(24), _font(path), _text(path, 24, renderer, ttf),
    _str(""),
    _color(255, 255, 255, 255),
    _pos(0, 0)
{
}

void SDL2Text::setText(const std::string& str)
{
    this->_text.setText(str);
    this->_str = str;
}

std::string SDL2Text::getText() const
{
    return this->_str;
}

void SDL2Text::setFont(const std::string& font)
{
    this->_text.setFont(font, this->_size, this->_ttf);
    this->_font = font;
}

std::string SDL2Text::getFont() const
{
    return this->_font;
}

void SDL2Text::setFontSize(const unsigned int size)
{
    this->_size = size;
    this->_text.setFontSize(this->_font, this->_size, this->_ttf);
}

unsigned int SDL2Text::getFontSize() const
{
    return this->_size;
}

void SDL2Text::setColor(const Shared::Color& color)
{
    SDL2::color SDLcolor;
    this->_color = color;

    SDLcolor.a = color.A;
    SDLcolor.r = color.R;
    SDLcolor.b = color.B;
    SDLcolor.g = color.G;
    this->_text.setColor(SDLcolor);
}

Shared::Color SDL2Text::getColor() const
{
    return this->_color;
}

void SDL2Text::setPos(const Shared::Vector& pos)
{
    this->_pos = pos;
    this->_text.setPos(pos.getX(), pos.getY());
}

Shared::Vector SDL2Text::getPos() const
{
    return this->_pos;
}

void SDL2Text::draw() const
{
    this->_text.draw();
}
}
