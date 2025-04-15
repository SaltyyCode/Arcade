/*
** EPITECH PROJECT, 2025
** OOP
** File description:
** Arcade project
*/

#pragma once

#include "Models/IRect.hpp"
#include "Vector.hpp"
#include "Color.hpp"

namespace Arc {
    class NCursesRect : public Shared::Models::IRect {
        public:
            NCursesRect();
            ~NCursesRect() = default;

            void setSize(const Shared::Vector &size) override;
            Shared::Vector getSize() const override;

            void setPos(const Shared::Vector &pos) override;
            Shared::Vector getPos() const override;

            void setColor(const struct Shared::Color &color) override;
            struct Shared::Color &getColor() const override;

            void setOutlineColor(const struct Shared::Color &color) override;
            struct Shared::Color &getOutlineColor() const override;

            void setThickness(const int thickness) override;
            int getThickness() const override;

        private:
            Shared::Vector _size;
            Shared::Vector _pos;
            mutable Shared::Color _color;
            mutable Shared::Color _outlineColor;
            int _thickness;
    };
}