/*
** EPITECH PROJECT, 2024
** OOP
** File description:
** Arcade project
*/

#include "Games/Snake/ASnake.hpp"

ASnake::ASnake() {}

void ASnake::move()
{
    if (!_alive)
        return;

    Arc::Shared::Vector newHead = _body.front() + _direction;
    _body.insert(_body.begin(), newHead);

    if (_growthPending) {
        _growthPending = false;
    } else {
        _body.pop_back();
    }
}

void ASnake::grow() {
    _growthPending = true;
}
