/*
** EPITECH PROJECT, 2025
** SBC-Arcade
** File description:
** NcursesLibrary
*/

#pragma once

#include "ILibrary.hpp"
#include "IDisplay.hpp"
#include "Factories/IRectFactory.hpp"
#include "Factories/ISpriteFactory.hpp"
#include "Factories/IMusicFactory.hpp"
#include "Factories/ITextFactory.hpp"
#include "NCursesDisplay.hpp"
#include "Factories/NCursesRectFactory.hpp"
#include "Factories/NCursesSpriteFactory.hpp"
#include "Factories/NCursesMusicFactory.hpp"
#include "Factories/NCursesTextFactory.hpp"

namespace Arc {
    class NCursesLibrary : public Shared::ILibrary {
        public:
            NCursesLibrary() = default;
            ~NCursesLibrary() = default;

            Shared::IDisplay &getDisplay() override;
            Shared::Factories::IRectFactory &getRectFactory() override;
            Shared::Factories::ISpriteFactory &getSpriteFactory() override;
            Shared::Factories::IMusicFactory &getMusicFactory() override;
            Shared::Factories::ITextFactory &getTextFactory() override;

        private:
            NCursesDisplay _display;
            NCursesRectFactory _rectFactory;
            NCursesSpriteFactory _spriteFactory;
            NCursesMusicFactory _musicFactory;
            NCursesTextFactory _textFactory;
    };
}