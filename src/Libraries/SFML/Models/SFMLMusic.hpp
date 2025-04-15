/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SFMLMusic.hpp
*/

#pragma once

#include "Models/IMusic.hpp"
#include <SFML/Audio/Music.hpp>

namespace Arc {

class SFMLMusic : public Shared::Models::IMusic {
    public:
        SFMLMusic(const std::string& filename);
        ~SFMLMusic() = default;

        void reset() const override;
        void loop(bool isLoop) override;

        inline void play() const {_music.play();}
        inline void stop() const {_music.stop();}
    private:
        mutable sf::Music _music;
};
}
