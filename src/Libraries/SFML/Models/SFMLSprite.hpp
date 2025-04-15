/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SFMLSprite.hpp
*/

#pragma once

#include "Models/ISprite.hpp"
#include "Vector.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <memory>

namespace Arc {

class SFMLSprite : public Shared::Models::ISprite {
    public:
        SFMLSprite(std::shared_ptr<sf::Texture> texture);
        ~SFMLSprite() = default;

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

        inline const sf::Sprite& getSprite() const {return _sprite;}
    private:
        sf::Sprite _sprite;
        const std::shared_ptr<sf::Texture> _texture;
        Shared::Vector _scale = {1, 1};
        Shared::Vector _size;

        void updateSprite();
};
}
