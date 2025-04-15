/*
** EPITECH PROJECT, 2025
** OOP
** File description:
** Arcade project
*/

#include "Models/NCursesText.hpp"

namespace Arc {
    NCursesText::NCursesText() 
        : _text(""), _font("default"), _fontSize(12), _pos(0, 0)
    {
        _color = {255, 255, 255, 255};
    }

    void NCursesText::setText(const std::string &text)
    {
        _text = text;
    }

    std::string NCursesText::getText() const
    {
        return _text;
    }

    void NCursesText::setFont(const std::string &font)
    {
        _font = font;
    }

    std::string NCursesText::getFont() const
    {
        return _font;
    }

    void NCursesText::setFontSize(const unsigned int size)
    {
        _fontSize = size;
    }

    unsigned int NCursesText::getFontSize() const
    {
        return _fontSize;
    }

    void NCursesText::setColor(const Shared::Color &color)
    {
        _color = color;
    }

    Shared::Color NCursesText::getColor() const
    {
        return _color;
    }

    void NCursesText::setPos(const Shared::Vector &pos)
    {
        _pos = pos;
    }

    Shared::Vector NCursesText::getPos() const
    {
        return _pos;
    }
}