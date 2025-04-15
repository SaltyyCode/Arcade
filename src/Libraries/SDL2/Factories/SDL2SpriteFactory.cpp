/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SDL2SpriteFactory.cpp
*/

#include "SDL2SpriteFactory.hpp"
#include "../Models/SDL2Sprite.hpp"

namespace Arc {

std::shared_ptr<Shared::Models::ISprite> SDL2SpriteFactory::create()
{
    if (!this->_texture)
        throw std::runtime_error("Texture not loaded");
    return std::make_shared<SDL2Sprite>(this->_texture);
}

void SDL2SpriteFactory::load(std::string path)
{
    this->_texture = std::make_shared<SDL2Texture>(this->_renderer, path);
}
}
