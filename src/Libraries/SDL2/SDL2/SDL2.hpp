/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SDL2.hpp
*/

#pragma once

#include "Models/SDL2MusicWrapper.hpp"
#include "SDL2Font.hpp"
#include "SDL2Window.hpp"
#include "SDL2Renderer.hpp"
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_ttf.h>

namespace Arc {

class SDL2RectWrapper;
class SDL2Surface;
class SDL2Texture;

class SDL2 {
    public:

        struct color {
            Uint8 r;
            Uint8 g;
            Uint8 b;
            Uint8 a;
        };

        static SDL_Color convertColor(const SDL2::color& color);

        static std::string error();
        static std::string ttfError();
        static void init();
        static void ttfInit();
        static void ttfQuit();
        static void quit();

        static void mixerInit();
        static void mixerQuit();
        static std::string audioError();
        static Mix_Music *loadMusic(const std::string &path);
        static void freeMusic(Mix_Music *music);
        static void playMusic(const SDL2MusicWrapper &music, int loops);
        static void resumeMusic();
        static void stopMusic();

        static void ImgInit();
        static void ImgQuit();
        static std::string imgError();

        static int pollEvents(SDL_Event &event);

        static SDL_Window *createWindow(const std::string &title, int width, int height);
        static SDL_Renderer *createRenderer(SDL2Window &window);
        static void destroyWindow(SDL2Window& window);
        static void destroyRenderer(SDL2Renderer& renderer);

        static void setWindowSize(SDL2Window& window, int width, int height);
        static void setWindowTitle(SDL2Window& window, const std::string &title);

        static void renderClear(SDL2Renderer& renderer);
        static void renderPresent(SDL2Renderer& renderer);
        static void setRenderDrawColor(const SDL2Renderer& renderer, const SDL2::color &color);
        static void renderFillRect(SDL2Renderer& renderer, SDL_Rect &rect);
        static void renderDrawRect(SDL2Renderer& renderer, SDL_Rect &rect);

        static TTF_Font *openFont(const std::string &path, int size);
        static void closeFont(TTF_Font *font);
        static SDL_Surface *renderTextBlended(const SDL2Font& font, const std::string &text, const SDL2::color &color);
        static void freeSurface(SDL_Surface *surface);

        static SDL_Texture *createTextureFromSurface(const SDL2Renderer& renderer, const SDL2Surface& surface);
        static SDL_Texture *createTextureFromFile(const SDL2Renderer& renderer, const std::string &path);
        static void destroyTexture(SDL_Texture *texture);

        static void RenderCopy(const SDL2Renderer& renderer, const SDL2Texture& texture, const SDL_Rect *dst);
        static void getTextureSize(SDL2Texture& texture, SDL_Rect& rect);

        static void renderCopyEx(const SDL2Renderer& renderer, const SDL2Texture& texture, const SDL_Rect *src, const SDL_Rect *dst, double angle, const SDL_Point *center);
};
}
