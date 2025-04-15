/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SFMLSpriteFactory.cpp
*/

#include <iostream>
#include "SFMLSpriteFactory.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <memory>
#include <string>
namespace Arc {

void SFMLSpriteFactory::load(std::string path)
{
    // this->_texture = std::make_shared<sf::Texture>();
    if (!this->_texture->loadFromFile(path))
        std::cerr << "Error trying to loading texture: " << path << std::endl;
}

std::shared_ptr<Shared::Models::ISprite> SFMLSpriteFactory::create()
{
    return std::make_shared<SFMLSprite>(this->_texture);
}
}
