/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SDL2Sprite.hpp
*/

#pragma once

#include "Color.hpp"
#include "Models/ISprite.hpp"
#include <SDL2/SDL_rect.h>
#include <memory>
#include "../SDL2/SDL2Texture.hpp"
#include "Vector.hpp"

namespace Arc {

class SDL2Sprite : public Shared::Models::ISprite {
    public:
        SDL2Sprite(std::shared_ptr<SDL2Texture> texture);
        ~SDL2Sprite() = default;

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

        void draw(SDL2Renderer &renderer) const;
    private:
        std::shared_ptr<SDL2Texture> _texture;
        Shared::Vector _origin;
        SDL_Rect _rect;
        SDL_Rect _textRect;
        float _rotation;
        Shared::Color _color;
        Shared::Vector _scale;
};
}
