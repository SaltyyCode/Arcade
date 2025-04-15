/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SDL2Font.cpp
*/

#include "SDL2Font.hpp"
#include "Initializer/SDL2TTF.hpp"
#include "SDL2.hpp"
#include <memory>

namespace Arc {

SDL2Font::SDL2Font(const std::string& path, int size, std::shared_ptr<SDL2TTF> &ttf): _ttf(ttf)
{
    this->font = SDL2::openFont(path, size);
}

SDL2Font::~SDL2Font()
{
    SDL2::closeFont(this->font);
}

TTF_Font *SDL2Font::getFont() const
{
    return this->font;
}

SDL2Font& SDL2Font::operator=(SDL2Font&& other) noexcept
{
    if (this != &other) {
        SDL2::closeFont(this->font);
        this->font = other.font;
        other.font = nullptr;
    }
    return *this;
}
}
