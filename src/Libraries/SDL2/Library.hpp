/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** Library.hpp
*/

#pragma once

#include "Display.hpp"
#include "ILibrary.hpp"
#include "Factories/SDL2RectFactory.hpp"
#include "Factories/SDL2SpriteFactory.hpp"
#include "Factories/SDL2MusicFactory.hpp"
#include "Factories/SDL2TextFactory.hpp"

namespace Arc {

class SDL2Library : public Shared::ILibrary {
    public:
        SDL2Library();
        ~SDL2Library() = default;

        Shared::IDisplay &getDisplay() override;
        Shared::Factories::IRectFactory &getRectFactory() override;
        Shared::Factories::ISpriteFactory &getSpriteFactory() override;
        Shared::Factories::IMusicFactory &getMusicFactory() override;
        Shared::Factories::ITextFactory &getTextFactory() override;
    private:
        SDL2Display _display;
        SDL2RectFactory _rectFactory;
        SDL2SpriteFactory _spriteFactory;
        SDL2MusicFactory _musicFactory;
        SDL2TextFactory _textFactory;
};
}
