#pragma once

#include <ncurses.h>
#include <string>
#include <map>
#include "IDisplay.hpp"
#include "Models/IRect.hpp"
#include "Models/ISprite.hpp"
#include "Models/IMusic.hpp"
#include "Models/IText.hpp"
#include "Event.hpp"

namespace Arc {
    class NCursesDisplay : public Shared::IDisplay {
        public:
            NCursesDisplay();
            ~NCursesDisplay();

            void setTitle(const std::string &title) override;
            void setSize(const Shared::Vector size) override;
            void closeWindow() override;
            void draw(const Shared::Models::IRect& rect) override;
            void draw(const Shared::Models::ISprite& sprite) override;
            void draw(const Shared::Models::IText& text) override;
            void playMusic(const Shared::Models::IMusic &music) override;
            void stopMusic(const Shared::Models::IMusic &music) override;
            void restartMusic(const Shared::Models::IMusic &music) override;
            void clear() override;
            void display() override;
            bool pollEvents(struct Shared::Event& event) override;
            bool isOpen() override;

        private:
            void initColorPairs();
            int getColorPair(const Shared::Color &fg, const Shared::Color &bg);
            
            bool _isOpen;
            std::string _titre;
            bool keyPressed(struct Shared::Event& event, int ch);
            bool keyReleased(struct Shared::Event& event, int ch);
            Shared::KeyCode getKey(int ch);
            Shared::MouseEventType getMouseEvent(MEVENT& event);
            bool mouseEvent(struct Shared::Event& event, int ch);
            bool windowEvent(struct Shared::Event& event, int ch);
            std::map<std::pair<int, int>, int> _colorPairs;
            int _colorPairCounter;
    };
}