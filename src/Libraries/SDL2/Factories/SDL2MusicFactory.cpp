/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SDL2MusicFactory.cpp
*/

#include "SDL2MusicFactory.hpp"
#include "../Models/SDL2Music.hpp"

namespace Arc {

SDL2MusicFactory::SDL2MusicFactory()
{
    this->_mix = std::make_shared<SDL2Mix>();
}

std::shared_ptr<Shared::Models::IMusic> SDL2MusicFactory::create()
{
    return std::make_shared<SDL2Music>(_path, this->_mix);
}

void SDL2MusicFactory::load(std::string path)
{
    this->_path = path;
}
}
