/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SDL2.cpp
*/

#include "SDL2.hpp"
#include "SDL2Texture.hpp"
#include "SDL2Surface.hpp"
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_audio.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <stdexcept>

namespace Arc {

SDL_Color SDL2::convertColor(const SDL2::color &color)
{
    return {color.r, color.g, color.b, color.a};
}

std::string SDL2::error()
{
    return SDL_GetError();
}

void SDL2::init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        throw std::runtime_error("SDL could not initialize! SDL_Error: " + error());
}

void SDL2::quit()
{
    SDL_Quit();
}

std::string SDL2::ttfError()
{
    return TTF_GetError();
}

void SDL2::ttfInit()
{
    if (TTF_Init() == -1)
        throw std::runtime_error("SDL_ttf could not initialize! SDL_ttf Error: " + ttfError());
}

void SDL2::ttfQuit()
{
    TTF_Quit();
}

void SDL2::mixerInit()
{
    if (Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG | MIX_INIT_FLAC) != (MIX_INIT_MP3 | MIX_INIT_OGG | MIX_INIT_FLAC))
        throw std::runtime_error("SDL_mixer could not initialize! SDL_mixer Error: " + audioError());
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
        throw std::runtime_error("SDL_mixer could not initialize! SDL_mixer Error: " + audioError());
}

void SDL2::mixerQuit()
{
    if (Mix_QuerySpec(NULL, NULL, NULL) == 1)
        Mix_CloseAudio();
    Mix_Quit();
}

std::string SDL2::audioError()
{
    return Mix_GetError();
}

Mix_Music *SDL2::loadMusic(const std::string &path)
{
    Mix_Music *music = Mix_LoadMUS(path.c_str());

    if (!music)
        throw std::runtime_error("Failed to load music: " + audioError());
    return music;
}

void SDL2::freeMusic(Mix_Music *music)
{
    if (music)
        Mix_FreeMusic(music);
}

void SDL2::playMusic(const SDL2MusicWrapper &music, int loops)
{
    if (Mix_PlayMusic(music.getMusic(), loops) == -1)
        throw std::runtime_error("Failed to play music: " + audioError());
}

void SDL2::resumeMusic()
{
    Mix_ResumeMusic();
}

void SDL2::stopMusic()
{
    Mix_PauseMusic();
}

void SDL2::ImgInit()
{
    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_TIF;

    if (!(IMG_Init(imgFlags) & imgFlags))
        throw std::runtime_error("SDL_image could not initialize! SDL_image Error: " + imgError());
}

void SDL2::ImgQuit()
{
    IMG_Quit();
}

std::string SDL2::imgError()
{
    return IMG_GetError();
}

int SDL2::pollEvents(SDL_Event &event)
{
    return SDL_PollEvent(&event);
}

SDL_Window *SDL2::createWindow(const std::string &title, int width, int height)
{
    SDL_Window *window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    if (!window)
        throw std::runtime_error("Failed to create window: " + error());
    return window;
}

SDL_Renderer *SDL2::createRenderer(SDL2Window &window)
{
    SDL_Renderer *renderer;

    if (!window.getWindow())
        throw std::runtime_error("Window is not initialized");

    renderer = SDL_CreateRenderer(window.getWindow(), -1, SDL_RENDERER_ACCELERATED);

    if (!renderer)
        throw std::runtime_error("Failed to create renderer: " + error());
    return renderer;
}

void SDL2::destroyWindow(SDL2Window& window)
{
    SDL_DestroyWindow(window.getWindow());
    window.setWindow(nullptr);
}

void SDL2::destroyRenderer(SDL2Renderer& renderer)
{
    SDL_DestroyRenderer(renderer.getRenderer());
    renderer.setRenderer(nullptr);
}

void SDL2::setWindowSize(SDL2Window& window, int width, int height)
{
    if (!window.getWindow())
        throw std::runtime_error("Window is not initialized");
    SDL_SetWindowSize(window.getWindow(), width, height);
}

void SDL2::setWindowTitle(SDL2Window& window, const std::string &title)
{
    if (!window.getWindow())
        throw std::runtime_error("Window is not initialized");
    SDL_SetWindowTitle(window.getWindow(), title.c_str());
}

void SDL2::renderClear(SDL2Renderer& renderer)
{
    if (!renderer.getRenderer())
        throw std::runtime_error("Renderer is not initialized");
    SDL_RenderClear(renderer.getRenderer());
}

void SDL2::renderPresent(SDL2Renderer& renderer)
{
    if (!renderer.getRenderer())
        throw std::runtime_error("Renderer is not initialized");
    SDL_RenderPresent(renderer.getRenderer());
}

void SDL2::setRenderDrawColor(const SDL2Renderer& renderer, const SDL2::color &color)
{
    if (!renderer.getRenderer())
        throw std::runtime_error("Renderer is not initialized");
    SDL_SetRenderDrawColor(renderer.getRenderer(), color.r, color.g, color.b, color.a);
}

void SDL2::renderFillRect(SDL2Renderer& renderer, SDL_Rect &rect)
{
    if (!renderer.getRenderer())
        throw std::runtime_error("Renderer is not initialized");
    SDL_RenderFillRect(renderer.getRenderer(), &rect);
}

void SDL2::renderDrawRect(SDL2Renderer& renderer, SDL_Rect &rect)
{
    if (!renderer.getRenderer())
        throw std::runtime_error("Renderer is not initialized");
    SDL_RenderDrawRect(renderer.getRenderer(), &rect);
}

TTF_Font *SDL2::openFont(const std::string &path, int size)
{
    TTF_Font *font = TTF_OpenFont(path.c_str(), size);
    if (!font)
        throw std::runtime_error("Failed to load font: " + ttfError());
    return font;
}

void SDL2::closeFont(TTF_Font *font)
{
    if (font)
        TTF_CloseFont(font);
}

SDL_Surface *SDL2::renderTextBlended(const SDL2Font &font, const std::string &text, const SDL2::color &color)
{
    SDL_Surface *surface;
    SDL_Color SDLColor;

    SDLColor.a = color.a;
    SDLColor.r = color.r;
    SDLColor.g  = color.g;
    SDLColor.b = color.b;
    surface = TTF_RenderText_Blended(font.getFont(), text.c_str(), SDLColor);
    if (!surface)
        throw std::runtime_error("Failed to Render Text: " + ttfError());
    return surface;
}

void SDL2::freeSurface(SDL_Surface *surface)
{
    if (surface)
        SDL_FreeSurface(surface);
}

SDL_Texture *SDL2::createTextureFromSurface(const SDL2Renderer &renderer, const SDL2Surface &surface)
{
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer.getRenderer(), surface.getSurface());

    if (!texture)
        throw std::runtime_error("Failed to create texture from surface: " + error());
    return texture;
}

SDL_Texture *SDL2::createTextureFromFile(const SDL2Renderer &renderer, const std::string &path)
{
    SDL_Texture *texture = IMG_LoadTexture(renderer.getRenderer(), path.c_str());

    if (!texture)
        throw std::runtime_error("Failed to create texture from file: " + error());
    return texture;
}

void SDL2::destroyTexture(SDL_Texture *texture)
{
    if (texture)
        SDL_DestroyTexture(texture);
}

void SDL2::RenderCopy(const SDL2Renderer &renderer, const SDL2Texture &texture, const SDL_Rect *dst)
{
    if (SDL_RenderCopy(renderer.getRenderer(), texture.getTexture(), nullptr, dst))
        std::cerr << "Error copying texture: " << ttfError() << std::endl;
}

void SDL2::getTextureSize(SDL2Texture &texture, SDL_Rect &rect)
{
    SDL_QueryTexture(texture.getTexture(), nullptr, nullptr, &rect.w, &rect.h);
}

void SDL2::renderCopyEx(const SDL2Renderer &renderer, const SDL2Texture &texture, const SDL_Rect *src, const SDL_Rect *dst, double angle, const SDL_Point *center)
{
if (SDL_RenderCopyEx(renderer.getRenderer(), texture.getTexture(), src, dst, angle, center, SDL_FLIP_NONE))
    std::cerr << "Error copying texture: " << ttfError() << std::endl;
}
}
