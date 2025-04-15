/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** SDL2RectWrapper.cpp
*/

#include "SDL2RectWrapper.hpp"
#include <SDL2/SDL_error.h>
namespace Arc  {

SDL2RectWrapper::SDL2RectWrapper(int x, int y, int w, int h): _rect({x, y, w, h}), _thickness(0),
    _outlineColor({255, 255, 255, 255}), _fillColor({255, 255, 255, 255})
{}

void SDL2RectWrapper::setPos(int x, int y)
{
    this->_rect.x = x;
    this->_rect.y = y;
}

void SDL2RectWrapper::setSize(int w, int h)
{
    this->_rect.w = w;
    this->_rect.h = h;
}

void SDL2RectWrapper::setFillColor(const Shared::Color &color)
{
    this->_fillColor.r = color.R;
    this->_fillColor.g = color.G;
    this->_fillColor.b = color.B;
    this->_fillColor.a = color.A;
}

void SDL2RectWrapper::setOutlineColor(const Shared::Color &color)
{
    this->_outlineColor.r = color.R;
    this->_outlineColor.g = color.G;
    this->_outlineColor.b = color.B;
    this->_outlineColor.a = color.A;
}

void SDL2RectWrapper::setThickness(int thickness)
{
    this->_thickness = thickness;
}

const SDL_Rect& SDL2RectWrapper::getRect() const
{
    return this->_rect;
}

void SDL2RectWrapper::draw(SDL2Renderer &renderer) const
{
    SDL_Rect tmpRect = this->_rect;

    SDL2::setRenderDrawColor(renderer, this->_fillColor);
    SDL2::renderFillRect(renderer, tmpRect);
    SDL2::setRenderDrawColor(renderer, this->_outlineColor);
    for (int i = 0; i < this->_thickness; i++) {
        tmpRect.x -= 1;
        tmpRect.y -= 1;
        tmpRect.w += 2;
        tmpRect.h += 2;
        SDL2::renderDrawRect(renderer, tmpRect);
    }
}
}
