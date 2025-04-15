/*
** EPITECH PROJECT, 2025
** SBC-Arcade
** File description:
** IDisplay.hpp
*/

#pragma once

#include <string>
#include "Models/IRect.hpp"
#include "Models/ISprite.hpp"
#include "Models/IMusic.hpp"
#include "Models/IText.hpp"
#include "Event.hpp"

namespace Arc::Shared {
    class IDisplay {
        public:
            virtual ~IDisplay() = default;

            virtual void setTitle(const std::string &title) = 0;
            virtual void setSize(const Vector size) = 0;
            virtual void closeWindow() = 0;
            virtual void draw(const Arc::Shared::Models::IRect& rect) = 0;
            virtual void draw(const Arc::Shared::Models::ISprite& sprite) = 0;
            virtual void draw(const Arc::Shared::Models::IText& text) = 0;
            virtual void playMusic(const Arc::Shared::Models::IMusic &music) = 0;
            virtual void stopMusic(const Arc::Shared::Models::IMusic &music) = 0;
            virtual void restartMusic(const Arc::Shared::Models::IMusic &music) = 0;
            virtual void clear() = 0;
            virtual void display() = 0;
            virtual bool pollEvents(struct Event& event) = 0;
            virtual bool isOpen() = 0;
    };
}
