/*
** EPITECH PROJECT, 2025
** SBC-Arcade
** File description:
** IRect.hpp
*/

#pragma once

#include "Vector.hpp"
#include "Color.hpp"

namespace Arc::Shared::Models {
    class IRect {
        public:
            virtual ~IRect() = default;

            virtual void setSize(const Vector &size) = 0;
            virtual Vector getSize() const = 0;

            virtual void setPos(const Vector &pos) = 0;
            virtual Vector getPos() const = 0;

            virtual void setColor(const struct Color &color) = 0;
            virtual struct Color &getColor() const = 0;

            virtual void setOutlineColor(const struct Color &color) = 0;
            virtual struct Color &getOutlineColor() const = 0;

            virtual void setThickness(const int thickness) = 0;
            virtual int getThickness() const = 0;
    };
}
