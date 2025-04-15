/*
** EPITECH PROJECT, 2025
** SBC-Arcade
** File description:
** ITextFactory.hpp
*/

#pragma once

#include <string>
#include "IFactory.hpp"
#include "Models/IText.hpp"

namespace Arc::Shared::Factories {
        class ITextFactory : public IFactory<Arc::Shared::Models::IText> {
        public:
            virtual ~ITextFactory() = default;
            virtual void load(std::string path) = 0;
    };
}
