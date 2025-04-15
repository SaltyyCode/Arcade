/*
** EPITECH PROJECT, 2025
** Isnake.hpp
** File description:
** ISnake Interface for Arcade
*/

#pragma once

#include "Vector.hpp"
#include <string>
#include <vector>

class ISnake {
    public:
        virtual ~ISnake() = default;

        virtual bool isAlive() const = 0;
        virtual void setAlive(bool alive)  = 0;

        virtual void setSpeed(float speed) = 0;
        virtual float getSpeed() const = 0;

        virtual void move() = 0;
        virtual void changeDirection(const Arc::Shared::Vector& dir)  = 0;

        virtual std::vector<Arc::Shared::Vector> getBody() const = 0;
        virtual Arc::Shared::Vector getDirection() const = 0;

        virtual void grow() = 0;
        virtual Arc::Shared::Vector getHeadPosition() const = 0;
};
