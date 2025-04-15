/*
** EPITECH PROJECT, 2025
** OOP
** File description:
** Arcade project
*/

#include "Models/NCursesMusic.hpp"

namespace Arc {
    void NCursesMusic::reset() const
    {
    }

    void NCursesMusic::loop(bool isLoop)
    {
        _loop = isLoop;
    }
}