/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SDL2Music.hpp
*/

#pragma once

#include "Models/IMusic.hpp"
#include  "../SDL2/Models/SDL2MusicWrapper.hpp"
#include <memory>
#include "../SDL2/Initializer/SDL2Mix.hpp"

namespace Arc {

class SDL2Music : public Shared::Models::IMusic {
    public:
        SDL2Music(const std::string& path, std::shared_ptr<SDL2Mix> &mix);
        ~SDL2Music() = default;

        void reset() const override;
        void loop(bool isLoop) override;

        void play() const;
        void stop() const;
    private:
        std::shared_ptr<SDL2Mix> _mix;
        SDL2MusicWrapper _music;
        int _isLoop;
};
}
