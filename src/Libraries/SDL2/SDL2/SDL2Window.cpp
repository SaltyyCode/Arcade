/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** Window.cpp
*/

#include "SDL2Window.hpp"
#include "SDL2.hpp"
#include <SDL2/SDL_video.h>
#include "Models/SDL2FontLoader.hpp"

namespace Arc {

SDL2Window::SDL2Window(const std::string &title, int width, int height)
{
    SDL2::init();
    SDL2::mixerInit();
    this->_window = SDL2::createWindow(title, width, height);
}

SDL2Window::~SDL2Window()
{
    SDL2::destroyWindow(*this);
    SDL2FontLoader::cleanup();
    SDL2::mixerQuit();
    SDL2::quit();
}

void SDL2Window::setTitle(const std::string &title)
{
    SDL2::setWindowTitle(*this, title);
}

void SDL2Window::destroyWindow()
{
    SDL2::destroyWindow(*this);
}

void SDL2Window::setSize(int width, int height)
{
    SDL2::setWindowSize(*this, width, height);
}

SDL2Window& SDL2Window::operator=(SDL2Window&& other) noexcept
{
    if (this != &other) {
        SDL2::destroyWindow(*this);
        this->_window = other._window;
        other._window = nullptr;
    }
    return *this;
}
}
