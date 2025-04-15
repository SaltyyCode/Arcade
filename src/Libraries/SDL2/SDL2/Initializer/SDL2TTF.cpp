/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SDL2TTF.cpp
*/

#include "SDL2TTF.hpp"
#include "../SDL2.hpp"

namespace Arc {

SDL2TTF::SDL2TTF()
{
    SDL2::ttfInit();
}

SDL2TTF::~SDL2TTF()
{
    SDL2::ttfQuit();
}
}
