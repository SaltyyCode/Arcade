/*
** EPITECH PROJECT, 2025
** OOP
** File description:
** Arcade project
*/

#include "Factories/NCursesRectFactory.hpp"
#include "Models/NCursesRect.hpp"
#include <memory>

namespace Arc {
    std::shared_ptr<Shared::Models::IRect> NCursesRectFactory::create()
    {
        return std::make_shared<NCursesRect>();
    }
}