/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SFMLText.hpp
*/

#pragma once

#include "Models/IText.hpp"
#include <SFML/Graphics/Text.hpp>
#include "Color.hpp"
#include "Vector.hpp"
#include <memory>
#include <string>

namespace Arc {

class SFMLText : public Shared::Models::IText {
    public:
        SFMLText(std::shared_ptr<sf::Font> font, const std::string& path);
        ~SFMLText() = default;

        void setText(const std::string &text) override;
        std::string getText() const override;
        void setFont(const std::string &font) noexcept(false) override;
        std::string getFont() const override;
        void setFontSize(unsigned int size) override;
        unsigned int getFontSize() const override;
        void setColor(const Shared::Color &color) override;
        Shared::Color getColor() const override;
        void setPos(const Shared::Vector &pos) override;
        Shared::Vector getPos() const override;

        inline const sf::Text& getTexte() const {return _text;}
    private:
        sf::Text _text;
        std::shared_ptr<sf::Font> _font;
        std::string _fontPath;
};
}
