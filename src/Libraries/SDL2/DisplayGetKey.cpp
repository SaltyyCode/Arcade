/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** DisplayGetKey.cpp
*/

#include "Display.hpp"
#include "Event.hpp"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>

namespace Arc {

Shared::KeyCode SDL2Display::getKeyCode(SDL_Keycode key)
{
    switch (key) {
        case SDLK_a: return Shared::KeyCode::K_A;
        case SDLK_b: return Shared::KeyCode::K_B;
        case SDLK_c: return Shared::KeyCode::K_C;
        case SDLK_d: return Shared::KeyCode::K_D;
        case SDLK_e: return Shared::KeyCode::K_E;
        case SDLK_f: return Shared::KeyCode::K_F;
        case SDLK_g: return Shared::KeyCode::K_G;
        case SDLK_h: return Shared::KeyCode::K_H;
        case SDLK_i: return Shared::KeyCode::K_I;
        case SDLK_j: return Shared::KeyCode::K_J;
        case SDLK_k: return Shared::KeyCode::K_K;
        case SDLK_l: return Shared::KeyCode::K_L;
        case SDLK_m: return Shared::KeyCode::K_M;
        case SDLK_n: return Shared::KeyCode::K_N;
        case SDLK_o: return Shared::KeyCode::K_O;
        case SDLK_p: return Shared::KeyCode::K_P;
        case SDLK_q: return Shared::KeyCode::K_Q;
        case SDLK_r: return Shared::KeyCode::K_R;
        case SDLK_s: return Shared::KeyCode::K_S;
        case SDLK_t: return Shared::KeyCode::K_T;
        case SDLK_u: return Shared::KeyCode::K_U;
        case SDLK_v: return Shared::KeyCode::K_V;
        case SDLK_w: return Shared::KeyCode::K_W;
        case SDLK_x: return Shared::KeyCode::K_X;
        case SDLK_y: return Shared::KeyCode::K_Y;
        case SDLK_z: return Shared::KeyCode::K_Z;

        case SDLK_0: return Shared::KeyCode::K_0;
        case SDLK_1: return Shared::KeyCode::K_1;
        case SDLK_2: return Shared::KeyCode::K_2;
        case SDLK_3: return Shared::KeyCode::K_3;
        case SDLK_4: return Shared::KeyCode::K_4;
        case SDLK_5: return Shared::KeyCode::K_5;
        case SDLK_6: return Shared::KeyCode::K_6;
        case SDLK_7: return Shared::KeyCode::K_7;
        case SDLK_8: return Shared::KeyCode::K_8;
        case SDLK_9: return Shared::KeyCode::K_9;

        case SDLK_SPACE: return Shared::KeyCode::K_SPACE;
        case SDLK_RETURN: return Shared::KeyCode::K_ENTER;
        case SDLK_ESCAPE: return Shared::KeyCode::K_ESCAPE;
        case SDLK_BACKSPACE: return Shared::KeyCode::K_BACKSPACE;
        case SDLK_TAB: return Shared::KeyCode::K_TAB;
        case SDLK_LSHIFT: return Shared::KeyCode::K_SHIFT;
        case SDLK_RSHIFT: return Shared::KeyCode::K_SHIFT;
        case SDLK_LCTRL: return Shared::KeyCode::K_CTRL;
        case SDLK_RCTRL: return Shared::KeyCode::K_CTRL;
        case SDLK_LALT: return Shared::KeyCode::K_ALT;
        case SDLK_RALT: return Shared::KeyCode::K_ALT;

        case SDLK_UP: return Shared::KeyCode::K_UP;
        case SDLK_DOWN: return Shared::KeyCode::K_DOWN;
        case SDLK_LEFT: return Shared::KeyCode::K_LEFT;
        case SDLK_RIGHT: return Shared::KeyCode::K_RIGHT;

        case SDLK_F1: return Shared::KeyCode::K_F1;
        case SDLK_F2: return Shared::KeyCode::K_F2;
        case SDLK_F3: return Shared::KeyCode::K_F3;
        case SDLK_F4: return Shared::KeyCode::K_F4;
        case SDLK_F5: return Shared::KeyCode::K_F5;
        case SDLK_F6: return Shared::KeyCode::K_F6;
        case SDLK_F7: return Shared::KeyCode::K_F7;
        case SDLK_F8: return Shared::KeyCode::K_F8;
        case SDLK_F9: return Shared::KeyCode::K_F9;
        case SDLK_F10: return Shared::KeyCode::K_F10;
        case SDLK_F11: return Shared::KeyCode::K_F11;
        case SDLK_F12: return Shared::KeyCode::K_F12;

        default: return Shared::KeyCode::K_NONE;
    }
}

Shared::MouseEventType SDL2Display::getMouseButton(Uint8 button, Uint32 type)
{
    if (type == SDL_MOUSEBUTTONDOWN) {
        switch (button) {
            case SDL_BUTTON_LEFT: return Shared::MouseEventType::MOUSE_CLICK_LEFT;
            case SDL_BUTTON_RIGHT: return Shared::MouseEventType::MOUSE_CLICK_RIGHT;
            case SDL_BUTTON_MIDDLE: return Shared::MouseEventType::MOUSE_CLICK_WHEEL;
            default: return Shared::MouseEventType::MOUSE_NONE;
        }
    }
    if (type == SDL_MOUSEBUTTONUP) {
        switch (button) {
            case SDL_BUTTON_LEFT: return Shared::MouseEventType::MOUSE_UNCLICK_LEFT;
            case SDL_BUTTON_RIGHT: return Shared::MouseEventType::MOUSE_UNCLICK_RIGHT;
            case SDL_BUTTON_MIDDLE: return Shared::MouseEventType::MOUSE_UNCLICK_WHEEL;
            default: return Shared::MouseEventType::MOUSE_NONE;
        }
    }
    return Shared::MouseEventType::MOUSE_NONE;
}
}
