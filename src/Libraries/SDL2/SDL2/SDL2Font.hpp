/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SDL2Font.hpp
*/

#pragma once

#include "Initializer/SDL2TTF.hpp"
#include <SDL2/SDL_ttf.h>
#include <memory>
#include <string>

namespace Arc {

class SDL2Font {
    public:
        SDL2Font(const std::string& path, int size, std::shared_ptr<SDL2TTF> &ttf);
        ~SDL2Font();

        TTF_Font *getFont() const;
        SDL2Font& operator=(const SDL2Font&) = delete;
        SDL2Font& operator=(SDL2Font&& other) noexcept;
    private:
        TTF_Font *font;
        std::shared_ptr<SDL2TTF> _ttf;
};
}
