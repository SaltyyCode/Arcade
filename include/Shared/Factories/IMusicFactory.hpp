/*
** EPITECH PROJECT, 2025
** SBC-Arcade
** File description:
** IMusicFactory.hpp
*/

#pragma once

#include "IFactory.hpp"
#include "Models/IMusic.hpp"
#include <string>

namespace Arc::Shared::Factories {
    class IMusicFactory : public IFactory<Arc::Shared::Models::IMusic> {
        public:
            virtual ~IMusicFactory() = default;
            virtual void load(std::string path) = 0;
    };
}
