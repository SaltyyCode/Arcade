/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SFMLDisplay.hpp
*/

#pragma once

#include "Event.hpp"
#include "IDisplay.hpp"
#include "Vector.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <memory>

namespace Arc {
class SFMLDisplay : public Shared::IDisplay {
    public:
        SFMLDisplay();
        ~SFMLDisplay() = default;

        void setTitle(const std::string &title) override;
        void setSize(Shared::Vector size) override;
        void closeWindow() override;
        void draw(const Arc::Shared::Models::IRect& rect) override;
        void draw(const Arc::Shared::Models::ISprite& sprite) override;
        void draw(const Arc::Shared::Models::IText& text) override;
        void playMusic(const Arc::Shared::Models::IMusic &music) override;
        void stopMusic(const Arc::Shared::Models::IMusic &music) override;
        void restartMusic(const Arc::Shared::Models::IMusic &music) override;
        void clear() override;
        void display() override;
        bool pollEvents(struct Shared::Event& event) override;
        bool isOpen() override;
        void openWindow();
    private:
        sf::Vector2<unsigned int> _size;
        std::string _titre = "SFML";
        std::unique_ptr<sf::RenderWindow> window;
        bool resized = false;
        sf::View view;

        bool keyPressed(struct Shared::Event& event, sf::Event& sfEvent);
        bool keyReleased(struct Shared::Event& event, sf::Event& sfEvent);
        Shared::KeyCode getKey(sf::Keyboard::Key);
        Shared::MouseEventType getMouseEvent(sf::Mouse::Button);
        Shared::MouseEventType getMouseEventType(struct sf::Event& event);
        bool mouseEvent(struct Shared::Event& event, sf::Event& sfEvent);
        bool windowEvent(struct Shared::Event& event, sf::Event& sfEvent);
};
}
