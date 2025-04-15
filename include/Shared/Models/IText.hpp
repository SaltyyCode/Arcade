/*
** EPITECH PROJECT, 2025
** SBC-Arcade
** File description:
** IText.hpp
*/

#pragma once

#include "Vector.hpp"
#include "Color.hpp"
#include <string>

namespace Arc::Shared::Models {
    class IText {
        public:
            virtual ~IText() = default;

            virtual void setText(const std::string &text) = 0;
            virtual std::string getText() const = 0;

            virtual void setFont(const std::string &font) = 0;
            virtual std::string getFont() const = 0;

            virtual void setFontSize(const unsigned int size) = 0;
            virtual unsigned int getFontSize() const = 0;

            virtual void setColor(const Color &color) = 0;
            virtual Color getColor() const = 0;

            virtual void setPos(const Vector &pos) = 0;
            virtual Vector getPos() const = 0;
    };
}
