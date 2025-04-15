/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SDL2Mix.cpp
*/

#include "SDL2Mix.hpp"
#include "../SDL2.hpp"

namespace Arc {

SDL2Mix::SDL2Mix()
{
    SDL2::mixerInit();
}

SDL2Mix::~SDL2Mix()
{
    SDL2::mixerQuit();
}
}
