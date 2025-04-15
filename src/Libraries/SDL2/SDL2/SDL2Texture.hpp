/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SDL2Texture.hpp
*/

#pragma once

#include "SDL2Renderer.hpp"
#include "SDL2Surface.hpp"
#include <SDL2/SDL_render.h>
#include <memory>

namespace Arc {

class SDL2Texture {
    public:
        SDL2Texture(std::shared_ptr<SDL2Renderer> &renderer, const std::string& path);
        SDL2Texture(std::shared_ptr<SDL2Renderer> &renderer, const SDL2Surface& surface);
        ~SDL2Texture();

        SDL_Texture *getTexture() const;
        SDL2Texture& operator=(const SDL2Texture&) = delete;
        SDL2Texture& operator=(SDL2Texture&& other) noexcept;
    private:
        SDL_Texture *_texture;
        std::shared_ptr<SDL2Renderer> _renderer;
};
}
