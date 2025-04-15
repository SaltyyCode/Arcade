#include "NCursesDisplay.hpp"
#include "Models/NCursesRect.hpp"
#include "Models/NCursesText.hpp"
#include "Models/NCursesSprite.hpp"
#include "Models/NCursesMusic.hpp"
#include <iostream>
#include <algorithm>
#include <unistd.h>

namespace Arc {

    NCursesDisplay::NCursesDisplay() : _isOpen(false), _titre("Arcade"), _colorPairCounter(1)
    {
        if (!isatty(STDOUT_FILENO)) {
            std::cerr << "Not a terminal - NCurses requires a terminal" << std::endl;
            throw std::runtime_error("NCurses initialization failed - not a terminal");
        }

        if (stdscr == nullptr) {
            initscr();
            if (stdscr == nullptr) {
                std::cerr << "Failed to initialize NCurses" << std::endl;
                throw std::runtime_error("NCurses initialization failed");
            }
        }
        
        cbreak();
        noecho();
        keypad(stdscr, TRUE);
        nodelay(stdscr, TRUE);
        curs_set(0);
        
        if (has_colors() == FALSE) {
            endwin();
            throw std::runtime_error("Your terminal does not support color");
        }
        start_color();
        mousemask(ALL_MOUSE_EVENTS, NULL);
        initColorPairs();
        
        _isOpen = true;
    }

    NCursesDisplay::~NCursesDisplay()
    {
        if (_isOpen) {
            closeWindow();
        }
    }

    void NCursesDisplay::setTitle(const std::string &title)
    {
        _titre = title;
    }

    void NCursesDisplay::setSize(const Shared::Vector size)
    {
        if (_isOpen) {
            resizeterm(static_cast<int>(size.getY()), static_cast<int>(size.getX()));
        }
    }

    void NCursesDisplay::closeWindow()
    {
        if (_isOpen) {
            endwin();
            _isOpen = false;
        }
    }

    void NCursesDisplay::draw(const Shared::Models::IRect& rect)
    {
        const NCursesRect *ncursesRect = dynamic_cast<const NCursesRect*>(&rect);
        
        if (!_isOpen || !ncursesRect)
            return;
    
        Shared::Vector pos = ncursesRect->getPos();
        Shared::Vector size = ncursesRect->getSize();
        Shared::Color color = ncursesRect->getColor();
        int thickness = ncursesRect->getThickness();

        int scaledX = static_cast<int>(pos.getX() / 16);
        int scaledY = static_cast<int>(pos.getY() / 16);
        int scaledWidth = std::max(1, static_cast<int>(size.getX() / 16));
        int scaledHeight = std::max(1, static_cast<int>(size.getY() / 16));
        
        if (thickness >= 0) {
            int colorPair = getColorPair(color, {0, 0, 0, 255});
            attron(COLOR_PAIR(colorPair));

            for (int x = scaledX; x < scaledX + scaledWidth; x++) {
                if (x >= 0 && x < COLS) {
                    if (scaledY >= 0 && scaledY < LINES) {
                        mvaddch(scaledY, x, '-');
                    }
                    if (scaledY + scaledHeight - 1 >= 0 && scaledY + scaledHeight - 1 < LINES) {
                        mvaddch(scaledY + scaledHeight - 1, x, '-');
                    }
                }
            }
            for (int y = scaledY; y < scaledY + scaledHeight; y++) {
                if (y >= 0 && y < LINES) {

                    if (scaledX >= 0 && scaledX < COLS) {
                        mvaddch(y, scaledX, '|');
                    }
                    
                    if (scaledX + scaledWidth - 1 >= 0 && scaledX + scaledWidth - 1 < COLS) {
                        mvaddch(y, scaledX + scaledWidth - 1, '|');
                    }
                }
            }
            
            if (scaledY >= 0 && scaledY < LINES && scaledX >= 0 && scaledX < COLS) {
                mvaddch(scaledY, scaledX, '+');
            }
            
            if (scaledY >= 0 && scaledY < LINES && scaledX + scaledWidth - 1 >= 0 && scaledX + scaledWidth - 1 < COLS) {
                mvaddch(scaledY, scaledX + scaledWidth - 1, '+');
            }
            
            if (scaledY + scaledHeight - 1 >= 0 && scaledY + scaledHeight - 1 < LINES && 
                scaledX >= 0 && scaledX < COLS) {
                mvaddch(scaledY + scaledHeight - 1, scaledX, '+');
            }
            
            if (scaledY + scaledHeight - 1 >= 0 && scaledY + scaledHeight - 1 < LINES && 
                scaledX + scaledWidth - 1 >= 0 && scaledX + scaledWidth - 1 < COLS) {
                mvaddch(scaledY + scaledHeight - 1, scaledX + scaledWidth - 1, '+');
            }

            if (thickness > 1) {
                for (int y = scaledY + 1; y < scaledY + scaledHeight - 1; y++) {
                    for (int x = scaledX + 1; x < scaledX + scaledWidth - 1; x++) {
                        if (y >= 0 && y < LINES && x >= 0 && x < COLS) {
                            mvaddch(y, x, ' ');
                        }
                    }
                }
            }
            
            attroff(COLOR_PAIR(colorPair));
        }
    }

void NCursesDisplay::draw(const Shared::Models::ISprite& sprite)
{
    const NCursesSprite *ncursesSprite = dynamic_cast<const NCursesSprite*>(&sprite);
    
    if (!_isOpen || !ncursesSprite)
        return;
    
    Shared::Vector pos = ncursesSprite->getPos();
    Shared::Color color = ncursesSprite->getColor();
    char character = ncursesSprite->getCharacter();
    
    int scaledX = static_cast<int>(std::round(pos.getX() / 16));
    int scaledY = static_cast<int>(std::round(pos.getY() / 16));
    
    int colorPair = getColorPair(color, {0, 0, 0, 255});
    
    attron(COLOR_PAIR(colorPair));
    
    if (scaledY >= 0 && scaledY < LINES && scaledX >= 0 && scaledX < COLS) {
        mvaddch(scaledY, scaledX, character);
    }
    
    attroff(COLOR_PAIR(colorPair));
}

void NCursesDisplay::draw(const Shared::Models::IText& text)
{
    const NCursesText *ncursesText = dynamic_cast<const NCursesText*>(&text);
    
    if (!_isOpen || !ncursesText)
        return;
    
    std::string content = ncursesText->getText();
    Shared::Vector pos = ncursesText->getPos();
    Shared::Color color = ncursesText->getColor();
    
    int scaledX = static_cast<int>(pos.getX() / 16);
    int scaledY = static_cast<int>(pos.getY() / 16);
    
    int colorPair = getColorPair(color, {0, 0, 0, 255});
    attron(COLOR_PAIR(colorPair));
    
    if (scaledY >= 0 && scaledY < LINES) {
        mvprintw(scaledY, scaledX, "%s", content.c_str());
    }
    
    attroff(COLOR_PAIR(colorPair));
}

    void NCursesDisplay::playMusic([[maybe_unused]] const Shared::Models::IMusic &music)
    {
    }

    void NCursesDisplay::stopMusic([[maybe_unused]] const Shared::Models::IMusic &music)
    {
    }

    void NCursesDisplay::restartMusic([[maybe_unused]] const Shared::Models::IMusic &music)
    {
    }

    void NCursesDisplay::clear()
    {
        if (_isOpen) {
            ::erase();
        }
    }

    void NCursesDisplay::display()
    {
        if (_isOpen) {
            refresh();
        }
    }

    bool NCursesDisplay::pollEvents(struct Shared::Event& event)
    {
        if (!_isOpen) return false;
        
        int ch = getch();
        if (ch == ERR) return false;
        
        event.type = Shared::EventType::NONE;
        event.data = std::monostate{};
        
        if (ch != KEY_MOUSE) {
            return this->keyPressed(event, ch);
        } else {
            return this->mouseEvent(event, ch);
        }
        
        return false;
    }
    
    bool NCursesDisplay::keyPressed(struct Shared::Event& event, int ch)
    {
        event.type = Shared::EventType::KEYBOARD;
        
        Shared::Event::KeyboardEvent keyEvent;
        keyEvent.eventType = Shared::KeyEventType::K_PRESS;
        keyEvent.keyCode = this->getKey(ch);
        
        event.data = keyEvent;
        return true;
    }
    
    bool NCursesDisplay::keyReleased(struct Shared::Event& event, int ch)
    {
        event.type = Shared::EventType::KEYBOARD;
        
        Shared::Event::KeyboardEvent keyEvent;
        keyEvent.eventType = Shared::KeyEventType::K_RELEASE;
        keyEvent.keyCode = this->getKey(ch);
        
        event.data = keyEvent;
        return true;
    }
    
    Shared::KeyCode NCursesDisplay::getKey(int ch)
    {
        switch (ch) {
            case 'a': case 'A': return Shared::KeyCode::K_A;
            case 'b': case 'B': return Shared::KeyCode::K_B;
            case 'c': case 'C': return Shared::KeyCode::K_C;
            case 'd': case 'D': return Shared::KeyCode::K_D;
            case 'e': case 'E': return Shared::KeyCode::K_E;
            case 'f': case 'F': return Shared::KeyCode::K_F;
            case 'g': case 'G': return Shared::KeyCode::K_G;
            case 'h': case 'H': return Shared::KeyCode::K_H;
            case 'i': case 'I': return Shared::KeyCode::K_I;
            case 'j': case 'J': return Shared::KeyCode::K_J;
            case 'k': case 'K': return Shared::KeyCode::K_K;
            case 'l': case 'L': return Shared::KeyCode::K_L;
            case 'm': case 'M': return Shared::KeyCode::K_M;
            case 'n': case 'N': return Shared::KeyCode::K_N;
            case 'o': case 'O': return Shared::KeyCode::K_O;
            case 'p': case 'P': return Shared::KeyCode::K_P;
            case 'q': case 'Q': return Shared::KeyCode::K_Q;
            case 'r': case 'R': return Shared::KeyCode::K_R;
            case 's': case 'S': return Shared::KeyCode::K_S;
            case 't': case 'T': return Shared::KeyCode::K_T;
            case 'u': case 'U': return Shared::KeyCode::K_U;
            case 'v': case 'V': return Shared::KeyCode::K_V;
            case 'w': case 'W': return Shared::KeyCode::K_W;
            case 'x': case 'X': return Shared::KeyCode::K_X;
            case 'y': case 'Y': return Shared::KeyCode::K_Y;
            case 'z': case 'Z': return Shared::KeyCode::K_Z;
            case '0': return Shared::KeyCode::K_0;
            case '1': return Shared::KeyCode::K_1;
            case '2': return Shared::KeyCode::K_2;
            case '3': return Shared::KeyCode::K_3;
            case '4': return Shared::KeyCode::K_4;
            case '5': return Shared::KeyCode::K_5;
            case '6': return Shared::KeyCode::K_6;
            case '7': return Shared::KeyCode::K_7;
            case '8': return Shared::KeyCode::K_8;
            case '9': return Shared::KeyCode::K_9;
            case ' ': return Shared::KeyCode::K_SPACE;
            case '\n': case KEY_ENTER: return Shared::KeyCode::K_ENTER;
            case 27: return Shared::KeyCode::K_ESCAPE;
            case KEY_BACKSPACE: return Shared::KeyCode::K_BACKSPACE;
            case '\t': return Shared::KeyCode::K_TAB;
            case KEY_UP: return Shared::KeyCode::K_UP;
            case KEY_DOWN: return Shared::KeyCode::K_DOWN;
            case KEY_LEFT: return Shared::KeyCode::K_LEFT;
            case KEY_RIGHT: return Shared::KeyCode::K_RIGHT;
            case KEY_F(1): return Shared::KeyCode::K_F1;
            case KEY_F(2): return Shared::KeyCode::K_F2;
            case KEY_F(3): return Shared::KeyCode::K_F3;
            case KEY_F(4): return Shared::KeyCode::K_F4;
            case KEY_F(5): return Shared::KeyCode::K_F5;
            case KEY_F(6): return Shared::KeyCode::K_F6;
            case KEY_F(7): return Shared::KeyCode::K_F7;
            case KEY_F(8): return Shared::KeyCode::K_F8;
            case KEY_F(9): return Shared::KeyCode::K_F9;
            case KEY_F(10): return Shared::KeyCode::K_F10;
            case KEY_F(11): return Shared::KeyCode::K_F11;
            case KEY_F(12): return Shared::KeyCode::K_F12;
            default: return Shared::KeyCode::K_NONE;
        }
    }
    
    Shared::MouseEventType NCursesDisplay::getMouseEvent(MEVENT& mouseEvent)
    {
        if (mouseEvent.bstate & BUTTON1_PRESSED)
            return Shared::MouseEventType::MOUSE_CLICK_LEFT;
        else if (mouseEvent.bstate & BUTTON1_RELEASED)
            return Shared::MouseEventType::MOUSE_UNCLICK_LEFT;
        else if (mouseEvent.bstate & BUTTON3_PRESSED)
            return Shared::MouseEventType::MOUSE_CLICK_RIGHT;
        else if (mouseEvent.bstate & BUTTON3_RELEASED)
            return Shared::MouseEventType::MOUSE_UNCLICK_RIGHT;
        else if (mouseEvent.bstate & BUTTON2_PRESSED)
            return Shared::MouseEventType::MOUSE_CLICK_WHEEL;
        else if (mouseEvent.bstate & BUTTON2_RELEASED)
            return Shared::MouseEventType::MOUSE_UNCLICK_WHEEL;
#ifdef BUTTON4_PRESSED
        else if (mouseEvent.bstate & BUTTON4_PRESSED)
            return Shared::MouseEventType::MOUSE_WHEEL_UP;
#endif
#ifdef BUTTON5_PRESSED
        else if (mouseEvent.bstate & BUTTON5_PRESSED)
            return Shared::MouseEventType::MOUSE_WHEEL_DOWN;
#endif
        return Shared::MouseEventType::MOUSE_NONE;
    }
    
    bool NCursesDisplay::mouseEvent(struct Shared::Event& event, [[maybe_unused]] int ch)
    {
        MEVENT mouseEvent;
        if (getmouse(&mouseEvent) != OK)
            return false;
            
        event.type = Shared::EventType::MOUSE;
        
        Shared::Vector position(mouseEvent.x, mouseEvent.y);
        Shared::MouseEventType eventType = this->getMouseEvent(mouseEvent);
        float deltaWheel = 0.0f;
        
        if (eventType == Shared::MouseEventType::MOUSE_WHEEL_UP)
            deltaWheel = 1.0f;
        else if (eventType == Shared::MouseEventType::MOUSE_WHEEL_DOWN)
            deltaWheel = -1.0f;
            
        event.data = Shared::Event::MouseEvent{position, eventType, deltaWheel};
        return true;
    }
    
    bool NCursesDisplay::windowEvent(struct Shared::Event& event, int ch)
    {
        event.type = Shared::EventType::WINDOW;
        
        if (ch == KEY_RESIZE) {
            event.data = Shared::Event::WindowEvent{
                Shared::WindowEventType::WINDOW_RESIZE, 
                Shared::Vector(COLS, LINES)
            };
            return true;
        }
        
        return false;
    }

    bool NCursesDisplay::isOpen()
    {
        return _isOpen;
    }

    void NCursesDisplay::initColorPairs()
    {
        init_pair(1, COLOR_WHITE, COLOR_BLACK);
        init_pair(2, COLOR_RED, COLOR_BLACK);
        init_pair(3, COLOR_GREEN, COLOR_BLACK);
        init_pair(4, COLOR_BLUE, COLOR_BLACK);
        init_pair(5, COLOR_YELLOW, COLOR_BLACK);
        init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(7, COLOR_CYAN, COLOR_BLACK);
        
        _colorPairCounter = 8;
    }

    int NCursesDisplay::getColorPair(const Shared::Color &fg, const Shared::Color &bg)
    {
        auto mapToTerminalColor = [](const Shared::Color &color) -> int {
            if (color.R > 200 && color.G < 100 && color.B < 100) return COLOR_RED;
            if (color.R < 100 && color.G > 200 && color.B < 100) return COLOR_GREEN;
            if (color.R < 100 && color.G < 100 && color.B > 200) return COLOR_BLUE;
            if (color.R > 200 && color.G > 200 && color.B < 100) return COLOR_YELLOW;
            if (color.R > 200 && color.G < 100 && color.B > 200) return COLOR_MAGENTA;
            if (color.R < 100 && color.G > 200 && color.B > 200) return COLOR_CYAN;
            if (color.R > 200 && color.G > 200 && color.B > 200) return COLOR_WHITE;
            return COLOR_BLACK;
        };
        
        int fgColor = mapToTerminalColor(fg);
        int bgColor = mapToTerminalColor(bg);
        
        auto key = std::make_pair(fgColor, bgColor);
        auto it = _colorPairs.find(key);
        
        if (it != _colorPairs.end()) {
            return it->second;
        }
        
        int pairNum = _colorPairCounter++;
        init_pair(pairNum, fgColor, bgColor);
        _colorPairs[key] = pairNum;
        
        return pairNum;
    }
}