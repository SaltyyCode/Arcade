/*
** EPITECH PROJECT, 2025
** OOP
** File description:
** Arcade project
*/

#pragma once

#include <string>
#include "Models/IText.hpp"
#include "Vector.hpp"
#include "Color.hpp"

namespace Arc {
    class NCursesText : public Shared::Models::IText {
        public:
            NCursesText();
            ~NCursesText() = default;

            void setText(const std::string &text) override;
            std::string getText() const override;

            void setFont(const std::string &font) override;
            std::string getFont() const override;

            void setFontSize(const unsigned int size) override;
            unsigned int getFontSize() const override;

            void setColor(const Shared::Color &color) override;
            Shared::Color getColor() const override;

            void setPos(const Shared::Vector &pos) override;
            Shared::Vector getPos() const override;

        private:
            std::string _text;
            std::string _font;
            unsigned int _fontSize;
            Shared::Color _color;
            Shared::Vector _pos;
    };
}