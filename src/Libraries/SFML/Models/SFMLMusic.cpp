/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SFMLMusic.cpp
*/

#include "SFMLMusic.hpp"
#include <iostream>

namespace Arc {

SFMLMusic::SFMLMusic(const std::string& filename)
{
    if (!this->_music.openFromFile(filename))
        std::cerr << "Error loading file: " << filename << std::endl;
}

void SFMLMusic::reset() const
{
    auto* self = const_cast<SFMLMusic*>(this);
    self->_music.setPlayingOffset(sf::Time::Zero);
    self->_music.play();
}

void SFMLMusic::loop(bool isLoop)
{
    this->_music.setLoop(isLoop);
}
}
