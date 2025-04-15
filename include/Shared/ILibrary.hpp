/*
** EPITECH PROJECT, 2025
** SBC-Arcade
** File description:
** ILibrary.hpp
*/

#pragma once

#include "Factories/IRectFactory.hpp"
#include "Factories/ISpriteFactory.hpp"
#include "Factories/IMusicFactory.hpp"
#include "Factories/ITextFactory.hpp"
#include "IDisplay.hpp"

namespace Arc::Shared {
    class ILibrary {
        public:
            virtual ~ILibrary() = default;
            virtual IDisplay &getDisplay() = 0;
            virtual Arc::Shared::Factories::IRectFactory &getRectFactory() = 0;
            virtual Arc::Shared::Factories::ISpriteFactory &getSpriteFactory() = 0;
            virtual Arc::Shared::Factories::IMusicFactory &getMusicFactory() = 0;
            virtual Arc::Shared::Factories::ITextFactory &getTextFactory() = 0;
    };
}
