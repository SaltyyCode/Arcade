/*
** EPITECH PROJECT, 2024
** OOP
** File description:
** Arcade project
*/

#include "Games/Nibbler/NibblerFruit.hpp"

NibblerFruit::NibblerFruit(const Arc::Shared::Vector &pos) : _position(pos) {}

Arc::Shared::Vector NibblerFruit::getPosition() const
{
    return _position;
}

void NibblerFruit::setPosition(const Arc::Shared::Vector &pos)
{
    _position = pos;
}
