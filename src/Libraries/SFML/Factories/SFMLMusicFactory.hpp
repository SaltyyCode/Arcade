/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SFMLMusicFactory.hpp
*/

#pragma once

#include "Factories/IMusicFactory.hpp"
#include "Models/IMusic.hpp"
#include <memory>

namespace Arc {

class SFMLMusicFactory : public Shared::Factories::IMusicFactory {
    public:
        SFMLMusicFactory() = default;
        ~SFMLMusicFactory() = default;

        void load(std::string path) override;
        std::shared_ptr<Shared::Models::IMusic> create() override;
    private:
        std::string _path = "default";
};
}
