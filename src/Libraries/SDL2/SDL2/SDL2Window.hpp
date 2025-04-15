/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** Window.hpp
*/

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <string>

namespace Arc {

class SDL2Window {
    public:
        SDL2Window(const std::string& title, int width, int height);
        ~SDL2Window();

        void destroyWindow();
        void setTitle(const std::string &title);
        void setSize(int width, int height);

        inline SDL_Window *getWindow() const {return _window;}
        inline void setWindow(SDL_Window *window) {_window = window;}
        SDL2Window& operator=(const SDL2Window&) = delete;
        SDL2Window& operator=(SDL2Window&& other) noexcept;
    private:
        SDL_Window *_window = nullptr;
};
}
