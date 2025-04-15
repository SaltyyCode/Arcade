/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SDL2TextWrapper.cpp
*/

#include "SDL2TextWrapper.hpp"
#include "SDL2FontLoader.hpp"
#include <string>

namespace Arc {

SDL2TextWrapper::SDL2TextWrapper(const std::string& font, int size, std::shared_ptr<SDL2Renderer> &renderer, std::shared_ptr<SDL2TTF> &ttf):
    _color(255, 255, 255, 255),
    _text("skibidi"),
    _font(SDL2FontLoader::getFont(font, size, ttf)),
    _surface(*_font, _text, this->_color),
    _texture(renderer, _surface),
    _rect(0, 0, _surface->w, _surface->h),
    _renderer(renderer)

{}

void SDL2TextWrapper::setText(const std::string& text)
{
    this->_text = text;
    this->_surface = SDL2Surface(*this->_font, text, this->_color);
    this->_texture = SDL2Texture(this->_renderer, this->_surface);
    this->_rect.w = this->_surface->w;
    this->_rect.h = this->_surface->h;
}

void SDL2TextWrapper::setFont(const std::string& path, int size, std::shared_ptr<SDL2TTF> &ttf)
{
    this->_font = SDL2FontLoader::getFont(path, size, ttf);
    this->_surface = SDL2Surface(*this->_font, this->_text, this->_color);
    this->_texture = SDL2Texture(this->_renderer, this->_surface);
    this->_rect.w = this->_surface->w;
    this->_rect.h = this->_surface->h;
}

void SDL2TextWrapper::setColor(const SDL2::color& color)
{
    this->_color = color;
    this->_surface = SDL2Surface(*this->_font, this->_text, this->_color);
    this->_texture = SDL2Texture(this->_renderer, this->_surface);
    this->_rect.w = this->_surface->w;
    this->_rect.h = this->_surface->h;
}

void SDL2TextWrapper::setPos(int x, int y)
{
    this->_rect.x = x;
    this->_rect.y = y;
}

void SDL2TextWrapper::draw() const
{
    SDL2::setRenderDrawColor(*this->_renderer, this->_color);
    SDL2::RenderCopy(*this->_renderer, this->_texture, &this->_rect);
}

}
