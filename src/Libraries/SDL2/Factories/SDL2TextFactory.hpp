/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SDL2TextFactory.hpp
*/

#pragma once

#include "Factories/ITextFactory.hpp"
#include "../SDL2/SDL2Renderer.hpp"
#include "../SDL2/Initializer/SDL2TTF.hpp"
#include <memory>

namespace Arc {

class SDL2TextFactory : public Shared::Factories::ITextFactory {
    public:
        SDL2TextFactory(std::shared_ptr<SDL2Renderer> &renderer);
        ~SDL2TextFactory() = default;

        std::shared_ptr<Shared::Models::IText> create() override;
        void load(std::string path) override;
    private:
        std::shared_ptr<SDL2TTF> _ttf;
        std::string _path = "";
        std::shared_ptr<SDL2Renderer> _renderer;
};
}
