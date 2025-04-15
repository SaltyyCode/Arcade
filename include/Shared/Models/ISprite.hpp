/*
** EPITECH PROJECT, 2025
** SBC-Arcade
** File description:
** ISprite.hpp
*/

#pragma once

#include "Vector.hpp"
#include "Color.hpp"

namespace Arc::Shared::Models {
class ISprite {
public:
    virtual ~ISprite() = default;

    virtual void setSize(const Vector &size) = 0;
    virtual Vector getSize() const = 0;

    virtual void setPos(const Vector &pos) = 0;
    virtual Vector getPos() const = 0;

    virtual void setRectPos(const Vector &pos) = 0;
    virtual Vector getRectPos() const = 0;

    virtual void setRectSize(const Vector &size) = 0;
    virtual Vector getRectSize() const = 0;

    virtual void setRotation(float rotation) = 0;
    virtual float getRotation() const = 0;

    virtual void setScale(const Vector &scale) = 0;
    virtual Vector getScale() const = 0;

    virtual void setOrigin(const Vector &origin) = 0;
    virtual Vector getOrigin() const = 0;

    virtual void setColor(const Color &color) = 0;
    virtual Color getColor() const = 0;
};
}
