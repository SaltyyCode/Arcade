/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SFMLRectFactory.cpp
*/

#include "SFMLRectFactory.hpp"
#include "../Models/SFMLRect.hpp"
#include <memory>

namespace Arc {

std::shared_ptr<Shared::Models::IRect>SFMLRectFactory::create()
{
    return std::make_shared<SFMLRect>();
}
}
