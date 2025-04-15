/*
** EPITECH PROJECT, 2024
** OOP
** File description:
** Arcade project
*/

#include "Games/Nibbler/NibblerSnake.hpp"

NibblerSnake::NibblerSnake(const Arc::Shared::Vector &startPos)
    : _direction(1, 0), _growthPending(false), _alive(true)
{
    _body.push_back(startPos);
    _body.push_back({startPos.getX() - 1, startPos.getY()});
    _body.push_back({startPos.getX() - 2, startPos.getY()});
    _body.push_back({startPos.getX() - 3, startPos.getY()});
}

void NibblerSnake::move()
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

void NibblerSnake::grow()
{
    _growthPending = true;
}

void NibblerSnake::changeDirection(const Arc::Shared::Vector &dir)
{
    if (_direction.getX() + dir.getX() == 0 && _direction.getY() + dir.getY() == 0)
        return;
    _direction = dir;
}

const Arc::Shared::Vector &NibblerSnake::getHeadPosition() const
{
    return _body.front();
}

const std::vector<Arc::Shared::Vector> &NibblerSnake::getBody() const
{
    return _body;
}

bool NibblerSnake::isAlive() const
{
    return _alive;
}

void NibblerSnake::setAlive(bool alive)
{
    _alive = alive;
}

Arc::Shared::Vector NibblerSnake::getDirection() const
{
    return _direction;
}
