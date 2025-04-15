/*
** EPITECH PROJECT, 2024
** OOP
** File description:
** Arcade project
*/
 
#pragma once
 
#include "Vector.hpp"
#include <variant>
 
namespace Arc::Shared {
        // General event categories
     enum EventType {
        NONE,
        MOUSE,      // Mouse-related events
        KEYBOARD,   // Keyboard-related events
        WINDOW      // Window-related events
    };
 
    // Mouse event types
    enum MouseEventType {
        MOUSE_NONE,
        MOUSE_CLICK_RIGHT,
        MOUSE_CLICK_LEFT,
        MOUSE_UNCLICK_RIGHT,
        MOUSE_UNCLICK_LEFT,
        MOUSE_MOVE,
        MOUSE_CLICK_WHEEL,
        MOUSE_UNCLICK_WHEEL,
        MOUSE_WHEEL_UP,
        MOUSE_WHEEL_DOWN
    };
 
    // Keyboard event types
    enum KeyEventType {
        K_EV_NONE,
        K_PRESS,
        K_RELEASE
    };
 
    // Key codes
    enum KeyCode {
        K_NONE,
        K_A,
        K_B,
        K_C,
        K_D,
        K_E,
        K_F,
        K_G,
        K_H,
        K_I,
        K_J,
        K_K,
        K_L,
        K_M,
        K_N,
        K_O,
        K_P,
        K_Q,
        K_R,
        K_S,
        K_T,
        K_U,
        K_V,
        K_W,
        K_X,
        K_Y,
        K_Z,
        K_0,
        K_1,
        K_2,
        K_3,
        K_4,
        K_5,
        K_6,
        K_7,
        K_8,
        K_9,
        K_SPACE,
        K_ENTER,
        K_ESCAPE,
        K_BACKSPACE,
        K_TAB,
        K_SHIFT,
        K_CTRL,
        K_ALT,
        K_CAPS_LOCK,
        K_UP,
        K_DOWN,
        K_LEFT,
        K_RIGHT,
        K_F1,
        K_F2,
        K_F3,
        K_F4,
        K_F5,
        K_F6,
        K_F7,
        K_F8,
        K_F9,
        K_F10,
        K_F11,
        K_F12
    };
 
    // Window event types
    enum WindowEventType {
        WINDOW_NONE,
        WINDOW_RESIZE,
        WINDOW_CLOSE
    };
 
    struct Event {
        EventType type = EventType::NONE;
 
        struct MouseEvent { Vector position; MouseEventType eventType; float deltaWheel; };
        struct KeyboardEvent { KeyEventType eventType; KeyCode keyCode; };
        struct WindowEvent { WindowEventType eventType; Vector size; };
 
        std::variant<std::monostate, MouseEvent, KeyboardEvent, WindowEvent> data;
        Event() : type(EventType::NONE), data(std::monostate{}) {}
    };
}
 
 