/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SDL2FontLoader.hpp
*/

#pragma once

#include <SDL2/SDL_ttf.h>
#include <map>
#include <memory>
#include <string>
#include <utility>
#include "../SDL2Font.hpp"

namespace Arc {

class SDL2FontLoader {
    public:
        static std::shared_ptr<SDL2Font> getFont(const std::string& fontPath, int fontSize, std::shared_ptr<SDL2TTF> &ttf);
        static void cleanup();
    private:
        static inline std::map<std::pair<int , std::string>, std::shared_ptr<SDL2Font>> _fonts;
};
}
