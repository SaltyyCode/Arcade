/*
** EPITECH PROJECT, 2025
** SBC-Arcade
** File description:
** IRectFactory.hpp
*/

#pragma once

#include "IFactory.hpp"
#include "Models/IRect.hpp"

namespace Arc::Shared::Factories {
    class IRectFactory : public IFactory<Arc::Shared::Models::IRect> {
        public:
            virtual ~IRectFactory() = default;
    };
}
