/*
** EPITECH PROJECT, 2024
** OOP
** File description:
** Arcade project
*/

#pragma once

#include "Vector.hpp"
#include <vector>

class NibblerSnake {
public:
    NibblerSnake(const Arc::Shared::Vector &startPos);

    void move();
    void grow();
    void changeDirection(const Arc::Shared::Vector &dir);
    Arc::Shared::Vector getDirection() const;


    const Arc::Shared::Vector &getHeadPosition() const;
    const std::vector<Arc::Shared::Vector> &getBody() const;
    bool isAlive() const;
    void setAlive(bool alive);

private:
    std::vector<Arc::Shared::Vector> _body;
    Arc::Shared::Vector _direction;
    bool _growthPending;
    bool _alive;
};
