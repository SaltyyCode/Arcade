/*
** EPITECH PROJECT, 2025
** OOP
** File description:
** Arcade project
*/

#include "Models/NCursesSprite.hpp"

namespace Arc {
    NCursesSprite::NCursesSprite() 
        : _path(""), _size(1, 1), _pos(0, 0), _rectPos(0, 0), _rectSize(1, 1),
          _scale(1, 1), _origin(0, 0), _rotation(0), _character('#')
    {
        _color = {255, 255, 255, 255};
    }

    void NCursesSprite::setSize(const Shared::Vector &size)
    {
        _size = size;
    }

    Shared::Vector NCursesSprite::getSize() const
    {
        return _size;
    }

    void NCursesSprite::setPos(const Shared::Vector &pos)
    {
        _pos = pos;
    }

    Shared::Vector NCursesSprite::getPos() const
    {
        return _pos;
    }

    void NCursesSprite::setRectPos(const Shared::Vector &pos)
    {
        _rectPos = pos;
    }

    Shared::Vector NCursesSprite::getRectPos() const
    {
        return _rectPos;
    }

    void NCursesSprite::setRectSize(const Shared::Vector &size)
    {
        _rectSize = size;
    }

    Shared::Vector NCursesSprite::getRectSize() const
    {
        return _rectSize;
    }

    void NCursesSprite::setRotation(float rotation)
    {
        _rotation = rotation;
    }

    float NCursesSprite::getRotation() const
    {
        return _rotation;
    }

    void NCursesSprite::setScale(const Shared::Vector &scale)
    {
        _scale = scale;
    }

    Shared::Vector NCursesSprite::getScale() const
    {
        return _scale;
    }

    void NCursesSprite::setOrigin(const Shared::Vector &origin)
    {
        _origin = origin;
    }

    Shared::Vector NCursesSprite::getOrigin() const
    {
        return _origin;
    }

    void NCursesSprite::setColor(const Shared::Color &color)
    {
        _color = color;
    }

    Shared::Color NCursesSprite::getColor() const
    {
        return _color;
    }
    
    char NCursesSprite::getCharacter() const
    {
        return _character;
    }
    
    void NCursesSprite::setCharacter(char c)
    {
        _character = c;
    }
    
    void NCursesSprite::setPath(const std::string &path)
    {
        _path = path;

        if (path.length() == 1) {
            _character = path[0];
        }
        else {
            _character = '#';
        }
    }
    
    std::string NCursesSprite::getPath() const
    {
        return _path;
    }
}