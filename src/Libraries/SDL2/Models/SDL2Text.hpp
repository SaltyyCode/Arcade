/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SDL2Text.h
*/

#pragma once

#include "Color.hpp"
#include "Models/IText.hpp"
#include "../SDL2/Models/SDL2TextWrapper.hpp"
#include "Vector.hpp"
#include "../SDL2/Initializer/SDL2TTF.hpp"
#include <memory>

namespace Arc {

class SDL2Text : public Shared::Models::IText {
    public:
        SDL2Text(const std::string& path, std::shared_ptr<SDL2Renderer> &renderer,
            std::shared_ptr<SDL2TTF> &ttf);
        ~SDL2Text() = default;

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

            void draw() const;
    private:
        std::shared_ptr<SDL2TTF> _ttf;
        int _size;
        std::string _font;
        SDL2TextWrapper _text;
        std::string _str;
        Shared::Color _color;
        Shared::Vector _pos;
};
}
