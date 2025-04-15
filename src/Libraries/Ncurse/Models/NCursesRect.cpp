/*
** EPITECH PROJECT, 2025
** OOP
** File description:
** Arcade project
*/

#include "NCursesRect.hpp"

namespace Arc {

    NCursesRect::NCursesRect() 
        : _size(1, 1), _pos(0, 0), _thickness(0)
    {
        _color = {255, 255, 255, 255};
        _outlineColor = {255, 255, 255, 255};
    }

    void NCursesRect::setSize(const Shared::Vector &size)
    {
        _size = size;
    }

    Shared::Vector NCursesRect::getSize() const
    {
        return _size;
    }

    void NCursesRect::setPos(const Shared::Vector &pos)
    {
        _pos = pos;
    }

    Shared::Vector NCursesRect::getPos() const
    {
        return _pos;
    }

    void NCursesRect::setColor(const struct Shared::Color &color)
    {
        _color = color;
    }

    struct Shared::Color &NCursesRect::getColor() const
    {
        return _color;
    }

    void NCursesRect::setOutlineColor(const struct Shared::Color &color)
    {
        _outlineColor = color;
    }

    struct Shared::Color &NCursesRect::getOutlineColor() const
    {
        return _outlineColor;
    }

    void NCursesRect::setThickness(const int thickness)
    {
        _thickness = thickness;
    }

    int NCursesRect::getThickness() const
    {
        return _thickness;
    }
}