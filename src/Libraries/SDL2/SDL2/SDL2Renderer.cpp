/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SDL2Renderer.cpp
*/

#include "SDL2Renderer.hpp"
#include "SDL2Window.hpp"
#include "SDL2.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

namespace Arc {

SDL2Renderer::SDL2Renderer(std::shared_ptr<SDL2Window> &window)
{
    this->_renderer = SDL2::createRenderer(*window);
    this->_window = window;
}

SDL2Renderer::~SDL2Renderer()
{
    this->destroyRenderer();
}

void SDL2Renderer::destroyRenderer()
{
    SDL2::destroyRenderer(*this);
}

void SDL2Renderer::clear()
{
    SDL2::setRenderDrawColor(*this, {0, 0, 0, 255});
    SDL2::renderClear(*this);
}

void SDL2Renderer::present()
{
    SDL2::renderPresent(*this);
}

SDL2Renderer& SDL2Renderer::operator=(SDL2Renderer&& other) noexcept
{
    if (this != &other) {
        SDL2::destroyRenderer(*this);
        this->_renderer = other._renderer;
        other._renderer = nullptr;
    }
    return *this;
}
}
