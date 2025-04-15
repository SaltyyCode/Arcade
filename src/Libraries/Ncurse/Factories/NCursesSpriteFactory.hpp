/*
** EPITECH PROJECT, 2025
** OOP
** File description:
** Arcade project
*/

#pragma once

#include "Factories/ISpriteFactory.hpp"
#include "Models/ISprite.hpp"
#include <memory>
#include <string>
#include <map>

namespace Arc {
    class NCursesSpriteFactory : public Shared::Factories::ISpriteFactory {
        public:
            NCursesSpriteFactory() = default;
            ~NCursesSpriteFactory() = default;

            std::shared_ptr<Shared::Models::ISprite> create() override;
            void load(std::string path) override;
        
        private:
            std::map<std::string, std::string> _loadedTextures;
    };
}