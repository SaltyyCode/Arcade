/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SDL2RectWrapper.hpp
*/

#pragma once

#include "Color.hpp"
#include "../SDL2.hpp"
#include <SDL2/SDL_rect.h>

namespace Arc {

class SDL2RectWrapper {
    public:
        SDL2RectWrapper(int x, int y, int w, int h);
        ~SDL2RectWrapper() = default;

        void setPos(int x, int y);
        void setSize(int w, int h);
        void setFillColor(const Shared::Color &color);
        void setOutlineColor(const Shared::Color &color);
        void setThickness(int thickness);

        void draw(SDL2Renderer &renderer) const;

        const SDL_Rect& getRect() const;
    private:
        SDL_Rect _rect;

        int _thickness;
        mutable SDL2::color _outlineColor;
        mutable SDL2::color _fillColor;
};
}
