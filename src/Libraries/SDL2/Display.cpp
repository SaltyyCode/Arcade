/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** Display.cpp
*/

#include <iostream>
#include "Display.hpp"
#include <SDL2/SDL_events.h>
#include <string>
#include <variant>
#include "Event.hpp"
#include "SDL2/SDL2.hpp"
#include "Vector.hpp"
#include "Models/SDL2Rect.hpp"
#include "Models/SDL2Sprite.hpp"
#include "Models/SDL2Text.hpp"
#include "Models/SDL2Music.hpp"

namespace Arc {

SDL2Display::SDL2Display()
{
    this->_window = std::make_shared<SDL2Window>(_title, _size.getX(), _size.getY());
    this->_renderer = std::make_shared<SDL2Renderer>(this->_window);
}

void SDL2Display::closeWindow()
{
    this->_renderer->destroyRenderer();
    this->_window->destroyWindow();
}

void SDL2Display::setTitle(const std::string &title)
{
    this->_window->setTitle(title);
    this->_title = title;
}

void SDL2Display::setSize(Shared::Vector size)
{
    this->_size = size;
    this->_window->setSize(size.getX(), size.getY());
}

void SDL2Display::draw(const Arc::Shared::Models::IRect& rect)
{
    const SDL2Rect *SDLRect = dynamic_cast<const SDL2Rect *>(&rect);

    if (!SDLRect)
        throw std::runtime_error("Invalid rectangle type");
    SDLRect->draw(*this->_renderer);
}

void SDL2Display::draw(const Arc::Shared::Models::ISprite& sprite)
{
    const SDL2Sprite *SDLSprite = dynamic_cast<const SDL2Sprite *>(&sprite);

    if (!SDLSprite)
        throw std::runtime_error("Invalid sprite type");
    SDLSprite->draw(*this->_renderer);
}

void SDL2Display::draw(const Arc::Shared::Models::IText& text)
{
    const SDL2Text *SDLText = dynamic_cast<const SDL2Text *>(&text);

    if (!SDLText)
        throw std::runtime_error("Invalid text type");
    SDLText->draw();
}

void SDL2Display::playMusic(const Arc::Shared::Models::IMusic &music)
{
    const SDL2Music *SDLMusic = dynamic_cast<const SDL2Music *>(&music);

    if (!SDLMusic)
        throw std::runtime_error("Invalid music type");
    SDLMusic->play();
}

void SDL2Display::stopMusic(const Arc::Shared::Models::IMusic &music)
{
    const SDL2Music *SDLMusic = dynamic_cast<const SDL2Music *>(&music);

    if (!SDLMusic)
        throw std::runtime_error("Invalid music type");
    SDLMusic->stop();
}

void SDL2Display::restartMusic(const Arc::Shared::Models::IMusic &music)
{
    const SDL2Music *SDLMusic = dynamic_cast<const SDL2Music *>(&music);

    if (!SDLMusic)
        throw std::runtime_error("Invalid music type");
    SDLMusic->reset();
}

void SDL2Display::clear()
{
    this->_renderer->clear();
}

void SDL2Display::display()
{
    this->_renderer->present();
}

bool SDL2Display::keyboard(struct Shared::Event &event, SDL_Event &sdlEvent)
{
    event.type = Shared::EventType::KEYBOARD;
    Shared::KeyEventType eventType = Shared::KeyEventType::K_EV_NONE;

    if (sdlEvent.type == SDL_KEYDOWN)
        eventType = Shared::KeyEventType::K_PRESS;
    else if (sdlEvent.type == SDL_KEYUP)
        eventType = Shared::KeyEventType::K_RELEASE;
    else
        return false;
    event.data = Shared::Event::KeyboardEvent {eventType, this->getKeyCode(sdlEvent.key.keysym.sym)};
    return true;
}

bool SDL2Display::mouse(struct Shared::Event &event, SDL_Event &sdlEvent)
{
    event.type = Shared::EventType::MOUSE;
    Shared::Vector vector(sdlEvent.button.x, sdlEvent.button.y);

    if (sdlEvent.type == SDL_MOUSEMOTION) {
        event.data = Shared::Event::MouseEvent {vector, Shared::MouseEventType::MOUSE_MOVE, 0.f};
        return true;
    }
    if (sdlEvent.type == SDL_MOUSEBUTTONDOWN || sdlEvent.type == SDL_MOUSEBUTTONUP) {
        event.data = Shared::Event::MouseEvent {vector, this->getMouseButton(sdlEvent.button.button, sdlEvent.type), 0.f};
        return true;
    }
    if (sdlEvent.type == SDL_MOUSEWHEEL) {
        event.data = Shared::Event::MouseEvent {vector, sdlEvent.wheel.y > 0 ? Shared::MouseEventType::MOUSE_WHEEL_UP : Shared::MouseEventType::MOUSE_WHEEL_DOWN, static_cast<float>(sdlEvent.wheel.y)};
        return true;
    }
    event.data = Shared::Event::MouseEvent {vector, Shared::MouseEventType::MOUSE_NONE, 0.f};
    return false;
}

bool SDL2Display::pollEvents(struct Shared::Event &event)
{
    SDL_Event sdlEvent;

    event.type = Shared::EventType::NONE;
    event.data = std::monostate{};
    if (!SDL2::pollEvents(sdlEvent))
        return false;
    if (sdlEvent.type == SDL_KEYDOWN || sdlEvent.type == SDL_KEYUP)
        return this->keyboard(event, sdlEvent);
    sdlEvent.button.button = SDL_BUTTON_LEFT;
    if (sdlEvent.type == SDL_MOUSEBUTTONDOWN || sdlEvent.type == SDL_MOUSEBUTTONUP
        || sdlEvent.type == SDL_MOUSEMOTION || sdlEvent.type == SDL_MOUSEWHEEL)
        return this->mouse(event, sdlEvent);
    if (sdlEvent.type == SDL_WINDOWEVENT && sdlEvent.window.event == SDL_WINDOWEVENT_RESIZED) {
        event.type = Shared::EventType::WINDOW;
        event.data = Shared::Event::WindowEvent {Shared::WindowEventType::WINDOW_RESIZE, Shared::Vector(sdlEvent.window.data1, sdlEvent.window.data2)};
        return true;
    }
    if (sdlEvent.type == SDL_QUIT) {
        event.type = Shared::EventType::WINDOW;
        event.data = Shared::Event::WindowEvent {Shared::WindowEventType::WINDOW_CLOSE, Shared::Vector()};
        return true;
    }
    return false;
}

bool SDL2Display::isOpen()
{
    return this->_window->getWindow() != nullptr && this->_renderer->getRenderer() != nullptr;
}
}
