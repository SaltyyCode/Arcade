/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SFMLlibrary.hpp
*/

#pragma once
#include "Factories/SFMLMusicFactory.hpp"
#include "Factories/SFMLRectFactory.hpp"
#include "Factories/SFMLSpriteFactory.hpp"
#include "Factories/SFMLTextFactory.hpp"
#include "ILibrary.hpp"
#include "SFMLDisplay.hpp"

namespace Arc {
class SFMLLibrary : public Shared::ILibrary {
    public:
        SFMLLibrary() = default;
        ~SFMLLibrary() = default;

        Shared::IDisplay &getDisplay() override;
        Shared::Factories::IRectFactory &getRectFactory() override;
        Shared::Factories::ISpriteFactory &getSpriteFactory() override;
        Shared::Factories::IMusicFactory &getMusicFactory() override;
        Shared::Factories::ITextFactory &getTextFactory() override;

    private:
        SFMLDisplay _display;
        SFMLTextFactory _textFactory;
        SFMLSpriteFactory _spriteFactory;
        SFMLRectFactory _rectFactory;
        SFMLMusicFactory _musicFactory;
};
}
