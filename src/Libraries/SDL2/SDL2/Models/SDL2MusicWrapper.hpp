/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SDL2MusicWrapper.hpp
*/

#pragma once

#include <SDL2/SDL_mixer.h>
#include <string>

namespace Arc {

class SDL2MusicWrapper {
    public:
        SDL2MusicWrapper(const std::string& path);;
        ~SDL2MusicWrapper();

        inline Mix_Music *getMusic() const {return this->_music;}
    private:
        Mix_Music *_music;
};
}
