/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SDL2Texture.cpp
*/

#include "SDL2Texture.hpp"
#include "SDL2Renderer.hpp"
#include "SDL2Surface.hpp"
namespace Arc {

SDL2Texture::SDL2Texture(std::shared_ptr<SDL2Renderer> &renderer, const std::string& path):
    _renderer(renderer)
{
    this->_texture = SDL2::createTextureFromFile(*renderer, path);
}

SDL2Texture::SDL2Texture(std::shared_ptr<SDL2Renderer> &renderer, const SDL2Surface& surface):
    _renderer(renderer)
{
    this->_texture = SDL2::createTextureFromSurface(*renderer, surface);
}

SDL2Texture::~SDL2Texture()
{
    SDL2::destroyTexture(this->_texture);
}

SDL_Texture *SDL2Texture::getTexture() const
{
    return this->_texture;
}

SDL2Texture& SDL2Texture::operator=(SDL2Texture&& other) noexcept
{
    if (this != &other) {
        SDL2::destroyTexture(this->_texture);
        this->_texture = other._texture;
        other._texture = nullptr;
    }
    return *this;
}
}
