/*
** EPITECH PROJECT, 2025
** OOP
** File description:
** Arcade project
*/

#pragma once

#include "Factories/IRectFactory.hpp"
#include "Models/IRect.hpp"
#include <memory>

namespace Arc {
    class NCursesRectFactory : public Shared::Factories::IRectFactory {
        public:
            NCursesRectFactory() = default;
            ~NCursesRectFactory() = default;

            std::shared_ptr<Shared::Models::IRect> create() override;
    };
}