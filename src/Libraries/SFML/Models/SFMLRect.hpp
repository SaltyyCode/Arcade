/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SFMLRect.hpp
*/

#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include "Models/IRect.hpp"
#include "Color.hpp"
#include "Vector.hpp"

namespace Arc {

class SFMLRect : public Shared::Models::IRect {
    public:
        SFMLRect() = default;
        ~SFMLRect() = default;

        void setSize(const Shared::Vector &size) override;
        Shared::Vector getSize() const override;

        void setPos(const Shared::Vector &pos) override;
        Shared::Vector getPos() const override;

        void setColor(const struct Shared::Color &color) override;
        struct Shared::Color &getColor() const override;

        void setOutlineColor(const struct Shared::Color &color) override;
        struct Shared::Color &getOutlineColor() const override;

        void setThickness(int thickness) override;
        int getThickness() const override;

        const sf::RectangleShape& getRectangle() const;
    private:
        sf::RectangleShape _rectangle;
        mutable struct Shared::Color _color;
        mutable struct Shared::Color _outlineColor;
};
}
