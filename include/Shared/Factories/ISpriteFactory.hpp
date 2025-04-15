/*
** EPITECH PROJECT, 2025
** SBC-Arcade
** File description:
** ISpriteFactory.hpp
*/

#pragma once

#include <string>
#include "IFactory.hpp"
#include "Models/ISprite.hpp"

namespace Arc::Shared::Factories {
class ISpriteFactory : public IFactory<Arc::Shared::Models::ISprite> {
public:
    virtual ~ISpriteFactory() = default;
    virtual void load(std::string path) = 0;
};
}
