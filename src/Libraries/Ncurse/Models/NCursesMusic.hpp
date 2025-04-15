/*
** EPITECH PROJECT, 2025
** OOP
** File description:
** Arcade project
*/

#pragma once

#include "Models/IMusic.hpp"

namespace Arc {
    class NCursesMusic : public Shared::Models::IMusic {
        public:
            NCursesMusic() = default;
            ~NCursesMusic() = default;

            void reset() const override;
            void loop(bool isLoop) override;

        private:
            bool _loop;
    };
}