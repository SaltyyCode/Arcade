/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SFMLMusicFactory.cpp
*/

#include "SFMLMusicFactory.hpp"
#include "../Models/SFMLMusic.hpp"
#include <memory>

namespace Arc {

void SFMLMusicFactory::load(std::string path)
{
    this->_path = path;
}

std::shared_ptr<Shared::Models::IMusic> SFMLMusicFactory::create()
{
    return std::make_shared<SFMLMusic>(_path);
}
}
