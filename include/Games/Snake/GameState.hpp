/*
** EPITECH PROJECT, 2025
** Gamestate.hpp
** File description:
** Gamestate class for Snake game 
*/

#pragma once
#include "Snake.hpp"
#include "Fruit.hpp"
#include <cstdlib>


class GameState {
public:
    GameState(int width, int height);
    ~GameState() = default;

    void update();
    void changeDirection(const Arc::Shared::Vector &dir);
    bool checkCollision() const;
    bool checkFruitCollision();
    void spawnFruit();

    const Snake &getSnake() const;
    const Fruit &getFruit() const;

private:
    Snake _snake;
    Fruit _fruit;
    int _width;
    int _height;
};
