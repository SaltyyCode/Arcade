/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SDL2Surface.cpp
*/

#include "SDL2Surface.hpp"
namespace Arc {

SDL2Surface::SDL2Surface(const SDL2Font& font, const std::string& text, const SDL2::color& color)
{
    std::string str = text;

    if (str.empty())
        str = "None";
    this->_surface = SDL2::renderTextBlended(font, str, color);
}

SDL2Surface::~SDL2Surface()
{
    SDL2::freeSurface(this->_surface);
}

SDL_Surface *SDL2Surface::getSurface() const
{
    return this->_surface;
}

SDL2Surface& SDL2Surface::operator=(SDL2Surface&& other) noexcept
{
    if (this != &other) {
        SDL2::freeSurface(this->_surface);
        this->_surface = other._surface;
        other._surface = nullptr;
    }
    return *this;
}
}
