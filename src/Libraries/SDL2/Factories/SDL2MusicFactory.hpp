/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SDL2MusicFactory.hpp
*/

#pragma once

#include "../SDL2/Initializer/SDL2Mix.hpp"
#include "Factories/IMusicFactory.hpp"
#include <memory>
namespace Arc {

class SDL2MusicFactory : public Shared::Factories::IMusicFactory {
    public:
        SDL2MusicFactory();
        ~SDL2MusicFactory() = default;

        std::shared_ptr<Shared::Models::IMusic> create() override;
        void load(std::string path) override;
    private:
        std::shared_ptr<SDL2Mix> _mix;
        std::string _path ="";
};
}
