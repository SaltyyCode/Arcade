/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SDL2RectFactory.hpp
*/

#pragma once

#include "Factories/IRectFactory.hpp"
namespace Arc {

class SDL2RectFactory : public Shared::Factories::IRectFactory {
    public:
        SDL2RectFactory() = default;
        ~SDL2RectFactory() = default;

        std::shared_ptr<Shared::Models::IRect> create() override;
};
}
