/*
** EPITECH PROJECT, 2025
** OOP
** File description:
** Arcade project
*/

#include "Factories/NCursesSpriteFactory.hpp"
#include "Models/NCursesSprite.hpp"

namespace Arc {
    void NCursesSpriteFactory::load(std::string path)
    {
        if (_loadedTextures.find(path) == _loadedTextures.end()) {
            _loadedTextures[path] = path;
        }
    }
    
    std::shared_ptr<Shared::Models::ISprite> NCursesSpriteFactory::create()
    {
        return std::make_shared<NCursesSprite>();
    }
}