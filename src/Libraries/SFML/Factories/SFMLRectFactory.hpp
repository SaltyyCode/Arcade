/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SFMLRectFactory.hpp
*/

#pragma once

#include "Factories/IRectFactory.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <memory>

namespace Arc {

class SFMLRectFactory : public Shared::Factories::IRectFactory {
    public:
        SFMLRectFactory() = default;
        ~SFMLRectFactory() = default;

        std::shared_ptr<Shared::Models::IRect> create() override;
    private:
};
}
