/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SDL2Renderer.hpp
*/

#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <memory>
#include "SDL2Window.hpp"

namespace Arc {
    class SDL2Renderer {
        public:
            SDL2Renderer(std::shared_ptr<SDL2Window> &window);
            ~SDL2Renderer();

            void destroyRenderer();
            void clear();
            void present();

            inline SDL_Renderer *getRenderer() const {return _renderer;}
            inline void setRenderer(SDL_Renderer *renderer) {_renderer = renderer;}
            SDL2Renderer& operator=(const SDL2Renderer&) = delete;
            SDL2Renderer& operator=(SDL2Renderer&& other) noexcept;
        private:
            SDL_Renderer *_renderer = nullptr;
            std::shared_ptr<SDL2Window> _window;
    };
}
