/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SDL2MusicWrapper.cpp
*/

#include "../SDL2.hpp"
#include "SDL2MusicWrapper.hpp"
#include <string>

namespace Arc {

SDL2MusicWrapper::SDL2MusicWrapper(const std::string& path)
{
    this->_music = SDL2::loadMusic(path);
}

SDL2MusicWrapper::~SDL2MusicWrapper()
{
    SDL2::freeMusic(this->_music);
    this->_music = nullptr;
}
}
