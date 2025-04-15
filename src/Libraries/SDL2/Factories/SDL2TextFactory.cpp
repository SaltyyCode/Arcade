/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SDL2TextFactory.cpp
*/

#include "SDL2TextFactory.hpp"
#include "../Models/SDL2Text.hpp"

namespace Arc {

SDL2TextFactory::SDL2TextFactory(std::shared_ptr<SDL2Renderer> &renderer): _renderer(renderer)
{
    this->_ttf = std::make_shared<SDL2TTF>();
}

std::shared_ptr<Shared::Models::IText> SDL2TextFactory::create()
{
    return std::make_shared<SDL2Text>(this->_path, this->_renderer, this->_ttf);
}

void SDL2TextFactory::load(std::string path)
{
    this->_path = path;
}
}
