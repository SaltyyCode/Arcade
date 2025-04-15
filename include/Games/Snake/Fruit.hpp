/*
** EPITECH PROJECT, 2025
** Fruit.hpp
** File description:
** Fruit class for Snake game 
*/

#pragma once
#include "Vector.hpp"

class Fruit {
public:
    Fruit(const Arc::Shared::Vector &pos);
    ~Fruit() = default;

    Arc::Shared::Vector getPosition() const;
    void setPosition(const Arc::Shared::Vector &pos);

private:
    Arc::Shared::Vector _position;
};
