/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SFMLTextFactory.cpp
*/

#include "SFMLTextFactory.hpp"
#include "Models/IText.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include <memory>
namespace Arc {

void SFMLTextFactory::load(std::string path)
{
    // this->_font = std::make_shared<sf::Font>();
    if (!this->_font->loadFromFile(path))
        std::cerr << "Error trying to load Font: " << path << std::endl;
    this->_path = path;
}

std::shared_ptr<Shared::Models::IText> SFMLTextFactory::create()
{
    return std::make_shared<SFMLText>(this->_font, this->_path);
}
}
