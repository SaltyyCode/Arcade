/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SDL2TextWrapper.hpp
*/

#pragma once

#include "../SDL2.hpp"
#include "../SDL2Font.hpp"
#include "../SDL2Surface.hpp"
#include "../SDL2Texture.hpp"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>
#include <memory>

namespace Arc {


class SDL2TextWrapper {
    public:
        SDL2TextWrapper(const std::string& font, int size, std::shared_ptr<SDL2Renderer> &renderer, std::shared_ptr<SDL2TTF> &ttf);
        ~SDL2TextWrapper() = default;

        void setText(const std::string &text);
        void setFont(const std::string& path, int size, std::shared_ptr<SDL2TTF> &ttf);
        inline void setFontSize(const std::string& path, int size, std::shared_ptr<SDL2TTF> &ttf) {setFont(path, size, ttf);}
        void setColor(const SDL2::color& color);
        void setPos(int x, int y);
        void draw() const;

    private:
        SDL2::color _color;
        std::string _text;
        std::shared_ptr<SDL2Font> _font;
        SDL2Surface _surface;
        SDL2Texture _texture;
        SDL_Rect _rect;
        std::shared_ptr<SDL2Renderer> _renderer;
};
}
