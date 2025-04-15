/*
** EPITECH PROJECT, 2025
** OOP
** File description:
** Arcade project
*/

#pragma once

#include "Models/ISprite.hpp"
#include "Vector.hpp"
#include "Color.hpp"
#include <string>

namespace Arc {
    class NCursesSprite : public Shared::Models::ISprite {
        public:
            NCursesSprite();
            ~NCursesSprite() = default;

            void setSize(const Shared::Vector &size) override;
            Shared::Vector getSize() const override;

            void setPos(const Shared::Vector &pos) override;
            Shared::Vector getPos() const override;

            void setRectPos(const Shared::Vector &pos) override;
            Shared::Vector getRectPos() const override;

            void setRectSize(const Shared::Vector &size) override;
            Shared::Vector getRectSize() const override;

            void setRotation(float rotation) override;
            float getRotation() const override;

            void setScale(const Shared::Vector &scale) override;
            Shared::Vector getScale() const override;

            void setOrigin(const Shared::Vector &origin) override;
            Shared::Vector getOrigin() const override;

            void setColor(const Shared::Color &color) override;
            Shared::Color getColor() const override;

            char getCharacter() const;
            void setCharacter(char c);
            void setPath(const std::string &path);
            std::string getPath() const;

        private:
            std::string _path;
            Shared::Vector _size;
            Shared::Vector _pos;
            Shared::Vector _rectPos;
            Shared::Vector _rectSize;
            Shared::Vector _scale;
            Shared::Vector _origin;
            float _rotation;
            Shared::Color _color;
            char _character;
    };
}