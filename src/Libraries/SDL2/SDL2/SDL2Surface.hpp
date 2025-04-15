/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SDL2Surface.hpp
*/

#pragma once

#include "SDL2.hpp"
#include "SDL2Font.hpp"
#include <SDL2/SDL_surface.h>
namespace Arc {

class SDL2Surface {
    public:
        SDL2Surface(const SDL2Font& font, const std::string& text, const SDL2::color& color);
        ~SDL2Surface();

        SDL_Surface *getSurface() const;
        inline SDL_Surface* operator->() const {return _surface;}
        SDL2Surface& operator=(const SDL2Surface&) = delete;
        SDL2Surface& operator=(SDL2Surface&& other) noexcept;

    private:
        SDL_Surface *_surface;
};
}
