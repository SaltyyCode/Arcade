/*
** EPITECH PROJECT, 2024
** OOP
** File description:
** Arcade project
*/

#pragma once

#include "NibblerSnake.hpp"
#include "NibblerFruit.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>

class NibblerGameState {
public:
    NibblerGameState(int width, int height);
    void update();
    void changeDirection(const Arc::Shared::Vector &dir);
    bool checkSelfCollision() const;
    void checkFruitCollision();
    bool isLevelComplete() const;
    void loadNextLevel();

    const NibblerSnake &getSnake() const;
    const std::vector<NibblerFruit> &getFruits() const;
    int getWidth() const;
    int getHeight() const;

    bool isWallAt(const Arc::Shared::Vector &pos) const;
    const std::vector<std::vector<bool>> &getWalls() const;
    int getLevel() const;

private:
    void generateLevelFruits();
    void generateWalls(int level);

    int _width;
    int _height;
    int _level;
    NibblerSnake _snake;
    std::vector<NibblerFruit> _fruits;
    std::vector<std::vector<bool>> _walls;
};
