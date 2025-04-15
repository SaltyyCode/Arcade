/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SDL2SpriteFactory.hpp
*/

#pragma once

#include "Factories/ISpriteFactory.hpp"
#include "../SDL2/SDL2Texture.hpp"
#include <memory>

namespace Arc {

class SDL2SpriteFactory : public Shared::Factories::ISpriteFactory {
    public:
        SDL2SpriteFactory(std::shared_ptr<SDL2Renderer>&renderer): _renderer(renderer) {};
        ~SDL2SpriteFactory() = default;

        std::shared_ptr<Shared::Models::ISprite> create() override;
        void load(std::string path) override;
    private:
        std::string _path = "";
        std::shared_ptr<SDL2Texture> _texture = nullptr;
        std::shared_ptr<SDL2Renderer> _renderer;
};
}
