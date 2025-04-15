/*
** EPITECH PROJECT, 2025
** SBC-Arcade
** File description:
** IMusic.hpp
*/

#pragma once

namespace Arc::Shared::Models {
class IMusic {
public:
    virtual ~IMusic() = default;
    virtual void reset() const = 0;
    virtual void loop(bool isLoop) = 0;
};
}
