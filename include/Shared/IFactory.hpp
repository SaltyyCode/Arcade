/*
** EPITECH PROJECT, 2025
** SBC-Arcade
** File description:
** IFactory.hpp
*/

#pragma once

#include <memory>

namespace Arc::Shared {
    template <typename T>
    class IFactory {
        public:
            virtual ~IFactory() = default;
            virtual std::shared_ptr<T> create() = 0;
    };
}
