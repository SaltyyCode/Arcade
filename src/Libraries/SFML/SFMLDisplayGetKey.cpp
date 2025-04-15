/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SFMLDisplayGetKey.cpp
*/

#include "Event.hpp"
#include "SFMLDisplay.hpp"
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>

namespace Arc {
Shared::KeyCode SFMLDisplay::getKey(sf::Keyboard::Key key)
{
    switch (key) {
        case sf::Keyboard::Key::A: return Shared::KeyCode::K_A;
        case sf::Keyboard::Key::B: return Shared::KeyCode::K_B;
        case sf::Keyboard::Key::C: return Shared::KeyCode::K_C;
        case sf::Keyboard::Key::D: return Shared::KeyCode::K_D;
        case sf::Keyboard::Key::E: return Shared::KeyCode::K_E;
        case sf::Keyboard::Key::F: return Shared::KeyCode::K_F;
        case sf::Keyboard::Key::G: return Shared::KeyCode::K_G;
        case sf::Keyboard::Key::H: return Shared::KeyCode::K_H;
        case sf::Keyboard::Key::I: return Shared::KeyCode::K_I;
        case sf::Keyboard::Key::J: return Shared::KeyCode::K_J;
        case sf::Keyboard::Key::K: return Shared::KeyCode::K_K;
        case sf::Keyboard::Key::L: return Shared::KeyCode::K_L;
        case sf::Keyboard::Key::M: return Shared::KeyCode::K_M;
        case sf::Keyboard::Key::N: return Shared::KeyCode::K_N;
        case sf::Keyboard::Key::O: return Shared::KeyCode::K_O;
        case sf::Keyboard::Key::P: return Shared::KeyCode::K_P;
        case sf::Keyboard::Key::Q: return Shared::KeyCode::K_Q;
        case sf::Keyboard::Key::R: return Shared::KeyCode::K_R;
        case sf::Keyboard::Key::S: return Shared::KeyCode::K_S;
        case sf::Keyboard::Key::T: return Shared::KeyCode::K_T;
        case sf::Keyboard::Key::U: return Shared::KeyCode::K_U;
        case sf::Keyboard::Key::V: return Shared::KeyCode::K_V;
        case sf::Keyboard::Key::W: return Shared::KeyCode::K_W;
        case sf::Keyboard::Key::X: return Shared::KeyCode::K_X;
        case sf::Keyboard::Key::Y: return Shared::KeyCode::K_Y;
        case sf::Keyboard::Key::Z: return Shared::KeyCode::K_Z;

        case sf::Keyboard::Key::Num0: return Shared::KeyCode::K_0;
        case sf::Keyboard::Key::Num1: return Shared::KeyCode::K_1;
        case sf::Keyboard::Key::Num2: return Shared::KeyCode::K_2;
        case sf::Keyboard::Key::Num3: return Shared::KeyCode::K_3;
        case sf::Keyboard::Key::Num4: return Shared::KeyCode::K_4;
        case sf::Keyboard::Key::Num5: return Shared::KeyCode::K_5;
        case sf::Keyboard::Key::Num6: return Shared::KeyCode::K_6;
        case sf::Keyboard::Key::Num7: return Shared::KeyCode::K_7;
        case sf::Keyboard::Key::Num8: return Shared::KeyCode::K_8;
        case sf::Keyboard::Key::Num9: return Shared::KeyCode::K_9;

        case sf::Keyboard::Key::Space: return Shared::KeyCode::K_SPACE;
        case sf::Keyboard::Key::Enter: return Shared::KeyCode::K_ENTER;
        case sf::Keyboard::Key::Escape: return Shared::KeyCode::K_ESCAPE;
        case sf::Keyboard::Key::Backspace: return Shared::KeyCode::K_BACKSPACE;
        case sf::Keyboard::Key::Tab: return Shared::KeyCode::K_TAB;
        case sf::Keyboard::Key::LShift: return Shared::KeyCode::K_SHIFT;
        case sf::Keyboard::Key::RShift: return Shared::KeyCode::K_SHIFT;
        case sf::Keyboard::Key::LControl: return Shared::KeyCode::K_CTRL;
        case sf::Keyboard::Key::RControl: return Shared::KeyCode::K_CTRL;
        case sf::Keyboard::Key::LAlt: return Shared::KeyCode::K_ALT;
        case sf::Keyboard::Key::RAlt: return Shared::KeyCode::K_ALT;

        case sf::Keyboard::Key::Up: return Shared::KeyCode::K_UP;
        case sf::Keyboard::Key::Down: return Shared::KeyCode::K_DOWN;
        case sf::Keyboard::Key::Left: return Shared::KeyCode::K_LEFT;
        case sf::Keyboard::Key::Right: return Shared::KeyCode::K_RIGHT;

        case sf::Keyboard::Key::F1: return Shared::KeyCode::K_F1;
        case sf::Keyboard::Key::F2: return Shared::KeyCode::K_F2;
        case sf::Keyboard::Key::F3: return Shared::KeyCode::K_F3;
        case sf::Keyboard::Key::F4: return Shared::KeyCode::K_F4;
        case sf::Keyboard::Key::F5: return Shared::KeyCode::K_F5;
        case sf::Keyboard::Key::F6: return Shared::KeyCode::K_F6;
        case sf::Keyboard::Key::F7: return Shared::KeyCode::K_F7;
        case sf::Keyboard::Key::F8: return Shared::KeyCode::K_F8;
        case sf::Keyboard::Key::F9: return Shared::KeyCode::K_F9;
        case sf::Keyboard::Key::F10: return Shared::KeyCode::K_F10;
        case sf::Keyboard::Key::F11: return Shared::KeyCode::K_F11;
        case sf::Keyboard::Key::F12: return Shared::KeyCode::K_F12;

        default: return Shared::KeyCode::K_NONE;
    }
}

Shared::MouseEventType SFMLDisplay::getMouseEventType(struct sf::Event& event)
{
    if (event.type == sf::Event::MouseButtonPressed) {
        switch (event.mouseButton.button) {
            case sf::Mouse::Button::Left: return Shared::MouseEventType::MOUSE_CLICK_LEFT;
            case sf::Mouse::Button::Right: return Shared::MouseEventType::MOUSE_CLICK_RIGHT;
            case sf::Mouse::Button::Middle: return Shared::MouseEventType::MOUSE_CLICK_WHEEL;
            default: return Shared::MouseEventType::MOUSE_NONE;
        }
    } else if (event.type == sf::Event::MouseButtonReleased) {
        switch (event.mouseButton.button) {
            case sf::Mouse::Button::Left: return Shared::MouseEventType::MOUSE_UNCLICK_LEFT;
            case sf::Mouse::Button::Right: return Shared::MouseEventType::MOUSE_UNCLICK_RIGHT;
            case sf::Mouse::Button::Middle: return Shared::MouseEventType::MOUSE_UNCLICK_WHEEL;
            default: return Shared::MouseEventType::MOUSE_NONE;
        }
    }
    return Shared::MouseEventType::MOUSE_NONE;
}

}
