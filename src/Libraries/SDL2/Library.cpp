/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** Library.cpp
*/

#include "Library.hpp"
#include "IDisplay.hpp"
#include "LibraryType.hpp"

namespace Arc {

extern "C" Shared::ILibrary *entryPoint()
{
    return new SDL2Library();
}

extern "C" LibraryType::Ltype type()
{
    return LibraryType::GRAPHIC;
}

extern "C" const char *name()
{
    return "SDL2";
}

SDL2Library::SDL2Library(): _spriteFactory(this->_display.getRenderer()),
    _textFactory(this->_display.getRenderer())
{}

Shared::IDisplay &SDL2Library::getDisplay()
{
    return this->_display;
}

Shared::Factories::IRectFactory &SDL2Library::getRectFactory()
{
    return this->_rectFactory;
}

Shared::Factories::ISpriteFactory &SDL2Library::getSpriteFactory()
{
    return this->_spriteFactory;
}

Shared::Factories::IMusicFactory &SDL2Library::getMusicFactory()
{
    return this->_musicFactory;
}

Shared::Factories::ITextFactory &SDL2Library::getTextFactory()
{
    return this->_textFactory;
}
}
