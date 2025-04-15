/*
** EPITECH PROJECT, 2025
** Snake.cpp
** File description:
** Snake object constructor
*/

#include "Games/Snake/Snake.hpp"

Snake::Snake(const Arc::Shared::Vector &startPos)
{
    _body.push_back(startPos);
    _body.push_back({startPos.getX() - 1, startPos.getY()});
    _body.push_back({startPos.getX() - 2, startPos.getY()});
    _body.push_back({startPos.getX() - 3, startPos.getY()});
}
