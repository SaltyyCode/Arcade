/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SFMLDisplay.cpp
*/

#include "SFMLDisplay.hpp"
#include "Event.hpp"
#include "Models/SFMLMusic.hpp"
#include "Models/SFMLRect.hpp"
#include "Models/SFMLSprite.hpp"
#include "Models/SFMLText.hpp"
#include "Vector.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <memory>
#include <optional>
#include <variant>

namespace Arc {

SFMLDisplay::SFMLDisplay(): _size(800, 600)
{
    this->window = std::make_unique<sf::RenderWindow>(
        sf::VideoMode(this->_size.x, this->_size.y), this->_titre,
        sf::Style::Resize | sf::Style::Close
    );
    this->view = this->window->getView();
}

void SFMLDisplay::setTitle(const std::string &title)
{
    this->_titre = title;

    if (!this->window || !this->window->isOpen())
        return;
    this->window->setTitle(title);
}

void SFMLDisplay::setSize(Shared::Vector size)
{
    this->_size.x = size.getX();
    this->_size.y = size.getY();

    if (!this->window || !this->window->isOpen())
        return;
    if (!this->resized)
        this->window->setSize(this->_size);
    this->view.setSize(this->_size.x, this->_size.y);
    this->view.setCenter(this->_size.x / 2.f, this->_size.y / 2.f);
    this->window->setView(this->view);
    this->resized = false;
}

void SFMLDisplay::closeWindow()
{
    if (!this->window || !this->window->isOpen())
        return;
    this->window->close();
}

bool SFMLDisplay::keyPressed(struct Shared::Event& event, sf::Event& sfEvent)
{
    event.type = Shared::EventType::KEYBOARD;

    if (sfEvent.type != sf::Event::KeyPressed)
        return false;
    event.data = Shared::Event::KeyboardEvent {Shared::KeyEventType::K_PRESS, this->getKey(sfEvent.key.code)};
    return true;
}

bool SFMLDisplay::keyReleased(struct Shared::Event& event, sf::Event& sfEvent)
{
    event.type = Shared::EventType::KEYBOARD;

    if (sfEvent.type != sf::Event::KeyReleased)
        return false;
    event.data = Shared::Event::KeyboardEvent {Shared::KeyEventType::K_RELEASE, this->getKey(sfEvent.key.code)};
    return true;
}

bool SFMLDisplay::mouseEvent(struct Shared::Event& event, sf::Event& sfEvent)
{
    Shared::Vector Vector;

    event.type = Shared::EventType::MOUSE;
    if (sfEvent.type == sf::Event::MouseButtonPressed) {
        Vector.setX(sfEvent.mouseButton.x);
        Vector.setY(sfEvent.mouseButton.y);
        event.data = Shared::Event::MouseEvent {Vector, this->getMouseEventType(sfEvent), 0.f};
        return true;
    }
    if (sfEvent.type == sf::Event::MouseButtonReleased) {
        Vector.setX(sfEvent.mouseButton.x);
        Vector.setY(sfEvent.mouseButton.y);
        event.data = Shared::Event::MouseEvent {Vector, this->getMouseEventType(sfEvent), 0.f};
        return true;
    }
    if (sfEvent.type == sf::Event::MouseMoved) {
        Vector.setX(sfEvent.mouseMove.x);
        Vector.setY(sfEvent.mouseMove.y);
        event.data = Shared::Event::MouseEvent {Vector, Shared::MouseEventType::MOUSE_MOVE, 0.f};
        return true;
    }
    if (sfEvent.type == sf::Event::MouseWheelScrolled) {
        Vector.setX(sfEvent.mouseWheel.x);
        Vector.setY(sfEvent.mouseWheel.y);
        event.data = Shared::Event::MouseEvent {Vector, (sfEvent.mouseWheel.delta > 0) ? Shared::MouseEventType::MOUSE_WHEEL_UP : Shared::MOUSE_WHEEL_DOWN, static_cast<float>(sfEvent.mouseWheel.delta)};
        return true;
    }
    event.data = Shared::Event::MouseEvent {Vector, Shared::MouseEventType::MOUSE_NONE, 0.f};
    return false;
}

bool SFMLDisplay::windowEvent(struct Shared::Event& event, sf::Event& sfEvent)
{
    event.type = Shared::EventType::WINDOW;
    if (sfEvent.type == sf::Event::Closed) {
        event.data = Shared::Event::WindowEvent {Shared::WindowEventType::WINDOW_CLOSE, Shared::Vector()};
        return true;
    }
    if (sfEvent.type == sf::Event::Resized) {
        event.data = Shared::Event::WindowEvent {Shared::WindowEventType::WINDOW_RESIZE, Shared::Vector(sfEvent.size.width, sfEvent.size.height)};
        this->resized = true;
        return true;
    }
    event.data = Shared::Event::WindowEvent {Shared::WindowEventType::WINDOW_NONE, Shared::Vector()};
    return false;
}

bool SFMLDisplay::pollEvents(struct Shared::Event& event)
{
    sf::Event sfEvent;

    event.type = Shared::EventType::NONE;
    event.data = std::monostate{};
    if (!this->window || !this->window->isOpen())
        return false;
    if (!this->window->pollEvent(sfEvent))
        return false;
    if (sfEvent.type == sf::Event::KeyPressed)
        return this->keyPressed(event, sfEvent);
    if (sfEvent.type == sf::Event::KeyReleased)
        return this->keyReleased(event, sfEvent);
    if (sfEvent.type == sf::Event::MouseButtonPressed || sfEvent.type == sf::Event::MouseButtonReleased ||
        sfEvent.type == sf::Event::MouseMoved || sfEvent.type == sf::Event::MouseWheelScrolled)
        return this->mouseEvent(event, sfEvent);
    if (sfEvent.type == sf::Event::Closed || sfEvent.type == sf::Event::Resized)
        return this->windowEvent(event, sfEvent);
    return false;
}

void SFMLDisplay::draw(const Arc::Shared::Models::IRect& rect)
{
    const SFMLRect *SFMLRect = dynamic_cast<const Arc::SFMLRect*>(&rect);

    if (!this->window || !this->window->isOpen() || !SFMLRect)
        return;
    this->window->draw(SFMLRect->getRectangle());
}

void SFMLDisplay::draw(const Arc::Shared::Models::ISprite& sprite)
{
    const SFMLSprite *SFMLSprite = dynamic_cast<const Arc::SFMLSprite*>(&sprite);

    if (!this->window || !this->window->isOpen() || !SFMLSprite)
        return;
    this->window->draw(SFMLSprite->getSprite());
}

void SFMLDisplay::draw(const Arc::Shared::Models::IText& text)
{
    const SFMLText *SFMLText = dynamic_cast<const Arc::SFMLText*>(&text);

    if (!this->window || !this->window->isOpen() || !SFMLText)
        return;
    this->window->draw(SFMLText->getTexte());
}

void SFMLDisplay::playMusic(const Arc::Shared::Models::IMusic &music)
{
    const SFMLMusic *SFMLMusic = dynamic_cast<const Arc::SFMLMusic*>(&music);

    if (!this->window || !this->window->isOpen() || !SFMLMusic)
        return;
    SFMLMusic->play();
}

void SFMLDisplay::stopMusic(const Arc::Shared::Models::IMusic &music)
{
    const SFMLMusic *SFMLMusic = dynamic_cast<const Arc::SFMLMusic*>(&music);

    if (!this->window || !this->window->isOpen() || !SFMLMusic)
        return;
    SFMLMusic->stop();
}

void SFMLDisplay::restartMusic(const Arc::Shared::Models::IMusic &music)
{
    const SFMLMusic *SFMLMusic = dynamic_cast<const Arc::SFMLMusic*>(&music);

    if (!this->window || !this->window->isOpen() || !SFMLMusic)
        return;
    SFMLMusic->reset();
}

void SFMLDisplay::clear()
{
    if (!this->window || !this->window->isOpen())
        return;
    this->window->clear();
}

void SFMLDisplay::display()
{
    if (!this->window || !this->window->isOpen())
        return;
    this->window->display();
}

bool SFMLDisplay::isOpen()
{
    if (!this->window)
        return false;
    return this->window->isOpen();
}

void SFMLDisplay::openWindow()
{
    if (this->window && this->window->isOpen())
        return;
    this->window = std::make_unique<sf::RenderWindow>(
        sf::VideoMode(this->_size.x, this->_size.y), this->_titre,
        sf::Style::Resize | sf::Style::Close
    );
    this->view = this->window->getView();
}
}
