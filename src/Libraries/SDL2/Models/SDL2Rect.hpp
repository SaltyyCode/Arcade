/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SDL2Rect.hpp
*/

#pragma once

#include "../SDL2/Models/SDL2RectWrapper.hpp"
#include "Models/IRect.hpp"
#include "Vector.hpp"
#include <SDL2/SDL_rect.h>

namespace Arc {

class SDL2Rect : public Shared::Models::IRect {
    public:
        SDL2Rect();
        ~SDL2Rect() = default;

        void setSize(const Shared::Vector &size) override;
        Shared::Vector getSize() const override;

        void setPos(const Shared::Vector &pos) override;
        Shared::Vector getPos() const override;

        void setColor(const struct Shared::Color &color) override;
        struct Shared::Color &getColor() const override;

        void setOutlineColor(const struct Shared::Color &color) override;
        struct Shared::Color &getOutlineColor() const override;

        void setThickness(int thickness) override;
        int getThickness() const override;

        void draw(SDL2Renderer &renderer) const;
    private:
        Shared::Vector _size;
        Shared::Vector _pos;
        int _thickness;
        SDL2RectWrapper _rect;
        mutable struct Shared::Color _color;
        mutable struct Shared::Color _outlineColor;
};
}
