/*
** EPITECH PROJECT, 2025
** ASnake.hpp
** File description:
** Abstract Snake class for Arcade
*/

#pragma once

#include "Vector.hpp"
#include "ISnake.hpp"

#include <vector>
#include <string>
#include <map>

class ASnake : public ISnake {
    public:
        ASnake();
        ~ASnake() override = default;

        float getSpeed() const override { return _speed; }
        void setSpeed(float speed) override { _speed = speed; }

        bool isAlive() const override { return _alive; }
        void setAlive(bool alive) override { _alive = alive; }

        Arc::Shared::Vector getDirection() const override { return _direction; }
        void changeDirection(const Arc::Shared::Vector& dir) override { _direction = dir; }

        std::vector<Arc::Shared::Vector> getBody() const override { return _body; }
        Arc::Shared::Vector getHeadPosition() const override { return _body.front(); }

        void move() override;
        void grow() override;

    protected:
        float _speed = 1.0f;
        bool _alive = true;
        Arc::Shared::Vector _direction = {1, 0};
        std::vector<Arc::Shared::Vector> _body;
        bool _growthPending = false;
};