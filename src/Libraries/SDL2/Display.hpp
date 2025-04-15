/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** Display.hpp
*/

#pragma once
#include "Event.hpp"
#include "IDisplay.hpp"
#include "SDL2/SDL2Window.hpp"
#include "SDL2/SDL2Renderer.hpp"
#include <memory>
#include <string>

namespace Arc {

class SDL2Display : public Shared::IDisplay {
    public:
        SDL2Display();
        ~SDL2Display() = default;

        void setTitle(const std::string &title) override;
        void setSize(Shared::Vector size) override;
        void closeWindow() override;
        void draw(const Arc::Shared::Models::IRect& rect) override;
        void draw(const Arc::Shared::Models::ISprite& sprite) override;
        void draw(const Arc::Shared::Models::IText& text) override;
        void playMusic(const Arc::Shared::Models::IMusic &music) override;
        void stopMusic(const Arc::Shared::Models::IMusic &music) override;
        void restartMusic(const Arc::Shared::Models::IMusic &music) override;
        void clear() override;
        void display() override;
        bool pollEvents(struct Shared::Event& event) override;
        bool isOpen() override;

        inline std::shared_ptr<SDL2Renderer> &getRenderer() {return this->_renderer;}
    private:
        Shared::Vector _size = {800, 600};
        std::string _title = "SDL2";
        std::shared_ptr<SDL2Window> _window;
        std::shared_ptr<SDL2Renderer> _renderer;

        bool keyboard(Shared::Event &arcadeEvent, SDL_Event &event);
        Shared::KeyCode getKeyCode(SDL_Keycode key);
        bool mouse(Shared::Event &arcadeEvent, SDL_Event &event);
        Shared::MouseEventType getMouseButton(Uint8 button, Uint32 type);
};

}
