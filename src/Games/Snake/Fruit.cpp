/*
** EPITECH PROJECT, 2025
** Fruit.cpp
** File description:
** Fruit methods for Snake game
*/

#include "Games/Snake/Fruit.hpp"

Fruit::Fruit(const Arc::Shared::Vector &pos) : _position(pos) {}

Arc::Shared::Vector Fruit::getPosition() const {
    return _position;
}

void Fruit::setPosition(const Arc::Shared::Vector &pos) {
    _position = pos;
}
