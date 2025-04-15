/*
** EPITECH PROJECT, 2025
** SBC-Arcade
** File description:
** NcursesLibrary
*/

#include "NCursesLibrary.hpp"
#include "Factories/IMusicFactory.hpp"
#include "Factories/ISpriteFactory.hpp"
#include "IDisplay.hpp"
#include "LibraryType.hpp"

namespace Arc {

extern "C" Shared::ILibrary *entryPoint()
{
    return new NCursesLibrary();
}
    
extern "C" LibraryType::Ltype type()
{
    return LibraryType::GRAPHIC;
}
    
extern "C" const char *name()
{
    return "NCurses";
}

Shared::IDisplay& NCursesLibrary::getDisplay()
{
    return this->_display;
}

Shared::Factories::IRectFactory& NCursesLibrary::getRectFactory()
{
    return this->_rectFactory;
}

Shared::Factories::ISpriteFactory& NCursesLibrary::getSpriteFactory()
{
    return this->_spriteFactory;
}

Shared::Factories::IMusicFactory& NCursesLibrary::getMusicFactory()
{
    return this->_musicFactory;
}

Shared::Factories::ITextFactory& NCursesLibrary::getTextFactory()
{
    return this->_textFactory;
}

}