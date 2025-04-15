/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SFMLSpriteFactory.hpp
*/

#pragma once

#include "Factories/ISpriteFactory.hpp"
#include "../Models/SFMLSprite.hpp"
#include "Models/ISprite.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <memory>
namespace Arc {

class SFMLSpriteFactory : public Shared::Factories::ISpriteFactory {
    public:
        SFMLSpriteFactory() = default;
        ~SFMLSpriteFactory() = default;

        void load(std::string path) override;
        std::shared_ptr<Shared::Models::ISprite> create() override;
    private:
        std::shared_ptr<sf::Texture> _texture = std::make_shared<sf::Texture>();
};
}
