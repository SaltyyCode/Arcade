/*
** EPITECH PROJECT, 2025
** GameState.cpp
** File description:
** GameState class for Snake game
*/

#include "Games/Snake/GameState.hpp"

GameState::GameState(int width, int height)
    : _snake({static_cast<float>(width / 2), static_cast<float>(height / 2)}),
      _fruit({0, 0}), // Valeur temporaire
      _width(width), _height(height)
{
    spawnFruit();
}

void GameState::update()
{
    _snake.move();

    if (checkFruitCollision()) {
        _snake.grow();
        spawnFruit();
    }
}

void GameState::changeDirection(const Arc::Shared::Vector &dir)
{
    _snake.changeDirection(dir);
}

bool GameState::checkCollision() const
{
    Arc::Shared::Vector head = _snake.getHeadPosition();

    if (head.getX() <= 0 || head.getX() >= _width - 1 ||
        head.getY() <= 0 || head.getY() >= _height - 1)
        return true;

    auto body = _snake.getBody();
    for (size_t i = 1; i < body.size(); ++i) {
        if (head.getX() == body[i].getX() && head.getY() == body[i].getY())
            return true;
    }
    return false;
}

bool GameState::checkFruitCollision()
{
    return _snake.getHeadPosition().getX() == _fruit.getPosition().getX() &&
           _snake.getHeadPosition().getY() == _fruit.getPosition().getY();
}

void GameState::spawnFruit()
{
    int x = std::rand() % (_width - 2) + 1;
    int y = std::rand() % (_height - 2) + 1;

    _fruit.setPosition({static_cast<float>(x), static_cast<float>(y)});
}

const Snake &GameState::getSnake() const
{
    return _snake;
}

const Fruit &GameState::getFruit() const
{
    return _fruit;
}
