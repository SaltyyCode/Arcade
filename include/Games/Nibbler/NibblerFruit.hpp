/*
** EPITECH PROJECT, 2025
** NibblerFruit.hpp
** File description:
** Fruit class for Nibbler game 
*/

#pragma once
#include "Vector.hpp"

class NibblerFruit {
public:
    NibblerFruit(const Arc::Shared::Vector &pos);
    ~NibblerFruit() = default;

    Arc::Shared::Vector getPosition() const;
    void setPosition(const Arc::Shared::Vector &pos);

private:
    Arc::Shared::Vector _position;
};
