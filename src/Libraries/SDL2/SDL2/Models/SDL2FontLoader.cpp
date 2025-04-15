/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SDL2FontLoader.cpp
*/

#include "SDL2FontLoader.hpp"
#include "../SDL2.hpp"
#include "../Initializer/SDL2TTF.hpp"
#include <memory>

namespace Arc {

std::shared_ptr<SDL2Font> SDL2FontLoader::getFont(const std::string& fontPath, int fontSize, std::shared_ptr<SDL2TTF> &ttf)
{
    auto it = _fonts.find({fontSize, fontPath});

    if (it != _fonts.end()) {
        return it->second;
    }
    _fonts[{fontSize, fontPath}] = std::make_shared<SDL2Font>(fontPath, fontSize, ttf);
    return _fonts[{fontSize, fontPath}];
}

void SDL2FontLoader::cleanup()
{
    _fonts.clear();
}
}
