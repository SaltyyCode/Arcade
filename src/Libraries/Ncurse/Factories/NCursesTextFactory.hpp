/*
** EPITECH PROJECT, 2025
** OOP
** File description:
** Arcade project
*/

#pragma once

#include "Factories/ITextFactory.hpp"
#include "Models/IText.hpp"
#include <memory>
#include <string>

namespace Arc {
    class NCursesTextFactory : public Shared::Factories::ITextFactory {
        public:
            NCursesTextFactory() = default;
            ~NCursesTextFactory() = default;

            std::shared_ptr<Shared::Models::IText> create() override;
            void load(std::string path) override;
        
        private:
            std::string _fontPath;
    };
}