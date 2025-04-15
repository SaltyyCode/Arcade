/*
** EPITECH PROJECT, 2024
** OOP
** File description:
** Arcade project
*/

#include "SFMLlibrary.hpp"
#include "Factories/IMusicFactory.hpp"
#include "Factories/ISpriteFactory.hpp"
#include "IDisplay.hpp"
#include "LibraryType.hpp"

namespace Arc {

extern "C" Shared::ILibrary *entryPoint()
{
    return new SFMLLibrary;
}

extern "C" LibraryType::Ltype type()
{
    return LibraryType::GRAPHIC;
}

extern "C" const char *name()
{
    return "SFML";
}

Shared::IDisplay& SFMLLibrary::getDisplay()
{
    return this->_display;
}

Shared::Factories::IRectFactory& SFMLLibrary::getRectFactory()
{
    return this->_rectFactory;
}

Shared::Factories::ISpriteFactory& SFMLLibrary::getSpriteFactory()
{
    return this->_spriteFactory;
}

Shared::Factories::IMusicFactory& SFMLLibrary::getMusicFactory()
{
    return this->_musicFactory;
}

Shared::Factories::ITextFactory& SFMLLibrary::getTextFactory()
{
    return this->_textFactory;
}

}
