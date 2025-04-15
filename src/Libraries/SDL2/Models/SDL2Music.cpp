/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SDL2Music.cpp
*/

#include "SDL2Music.hpp"
#include "../SDL2/SDL2.hpp"

namespace Arc {

SDL2Music::SDL2Music(const std::string& path, std::shared_ptr<SDL2Mix> &mix): _mix(mix), _music(path), _isLoop(1)
{}

void SDL2Music::reset() const
{
    SDL2::playMusic(this->_music, this->_isLoop);
}

void SDL2Music::loop(bool isLoop)
{
    if (isLoop)
        this->_isLoop = -1;
    else
        this->_isLoop = 1;

    SDL2::playMusic(this->_music, this->_isLoop);
}

void SDL2Music::play() const
{
    SDL2::resumeMusic();
}

void SDL2Music::stop() const
{
    SDL2::stopMusic();
}
}
