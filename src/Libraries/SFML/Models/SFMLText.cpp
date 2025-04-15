/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SFMLText.cpp
*/

#include "SFMLText.hpp"
#include "Color.hpp"
#include "Vector.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <memory>
#include <string>
#include <cstdint>

namespace Arc {

SFMLText::SFMLText(std::shared_ptr<sf::Font> font, const std::string& path): _font(font), _fontPath(path)
{
    this->_text.setFont(*font);
}

void SFMLText::setText(const std::string& text)
{
    this->_text.setString(text);
}

std::string SFMLText::getText() const
{
    return this->_text.getString();
}

void SFMLText::setFont(const std::string &font)
{
    this->_font = std::make_shared<sf::Font>();

    if (!this->_font->loadFromFile(font))
        std::cerr << "setFont: Can't load font: " << font << std::endl;
    this->_fontPath = font;
    this->_text.setFont(*this->_font);
}

std::string SFMLText::getFont() const
{
    return this->_fontPath;
}

void SFMLText::setFontSize(unsigned int size)
{
    this->_text.setCharacterSize(size);
}

unsigned int SFMLText::getFontSize() const
{
    return this->_text.getCharacterSize();
}

void SFMLText::setColor(const Shared::Color &color)
{
    this->_text.setFillColor({std::uint8_t(color.R), std::uint8_t(color.G),
        std::uint8_t(color.B), std::uint8_t(color.A)});
}

Shared::Color SFMLText::getColor() const
{
    struct Shared::Color resultColor;
    sf::Color color = this->_text.getFillColor();

    resultColor.A = color.a;
    resultColor.R = color.r;
    resultColor.G = color.g;
    resultColor.B = color.b;
    return resultColor;
}

void SFMLText::setPos(const Shared::Vector &pos)
{
    this->_text.setPosition({pos.getX(), pos.getY()});
}

Shared::Vector SFMLText::getPos() const
{
    sf::Vector2f vector = this->_text.getPosition();

    return {vector.x, vector.y};
}
}
