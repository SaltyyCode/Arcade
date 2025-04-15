/*
** EPITECH PROJECT, 2025
** SBC-Arcade
** File description:
** IGame.hpp
*/

#pragma once

#include "ILibrary.hpp"

namespace Arc::Shared {
    class IGame {
        public:
            virtual ~IGame() = default;
            virtual void init(ILibrary &lib) = 0;
            virtual void erase() = 0;
            virtual int getScore() const = 0;
            virtual void update(ILibrary& lib, float deltaTime) = 0;
            virtual void handleEvent(const struct Event &e) = 0;
            virtual void dump(ILibrary &lib) = 0;
    };
}
