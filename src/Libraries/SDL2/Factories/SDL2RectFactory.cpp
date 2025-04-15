/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SDL2RectFactory.cpp
*/

#include "../Models/SDL2Rect.hpp"
#include "SDL2RectFactory.hpp"

namespace Arc {

std::shared_ptr<Shared::Models::IRect> SDL2RectFactory::create()
{
    return std::make_shared<SDL2Rect>();
}
}
