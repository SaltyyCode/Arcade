/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SFMLTextFactory.hpp
*/

#pragma once

#include "Factories/ITextFactory.hpp"
#include "../Models/SFMLText.hpp"
#include "Models/IText.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <memory>

namespace Arc {

class SFMLTextFactory : public Shared::Factories::ITextFactory {
    public:
        SFMLTextFactory() = default;
        ~SFMLTextFactory() = default;

        void load(std::string path) override;
        std::shared_ptr<Shared::Models::IText> create() override;
    private:
        std::shared_ptr<sf::Font> _font = std::make_shared<sf::Font>();
        std::string _path;
};
}
