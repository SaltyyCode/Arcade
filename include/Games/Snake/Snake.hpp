/*
** EPITECH PROJECT, 2025
** Snake.hpp
** File description:
** Snake class for Snake game 
*/

#pragma once
#include "ASnake.hpp"

class Snake : public ASnake {
public:
    Snake(const Arc::Shared::Vector &startPos);
    ~Snake() override = default;
};
