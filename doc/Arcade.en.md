# Arcade Game and Graphical Library Implementation Guide

## Introduction

This document provides a comprehensive guide on how to implement custom Game and Graphical libraries for the Arcade system. The Arcade platform features a modular architecture where games and graphical libraries can be swapped at runtime, allowing for versatile gameplay experiences across different rendering engines.

## Table of Contents

1. [Shared Interface Overview](#shared-interface-overview)
2. [Implementing a Game Library](#implementing-a-game-library)
3. [Implementing a Graphical Library](#implementing-a-graphical-library)
4. [Arcade KeyBinds](#Arcade-keybinds)

## Shared Interface Overview

The Arcade system uses a set of shared interfaces to allow communication between the core, games, and graphical libraries. These interfaces are defined in the `Arc::Shared` namespace. Understanding these interfaces is crucial for implementing both games and graphical libraries.

### Key Interfaces

#### IGame Interface

```cpp
#pragma once

#include "Arc/Shared/ILibrary.hpp"

namespace Arc::Shared {
    class IGame {
        public:
            virtual ~IGame() = default;
            virtual void init(ILibrary &lib) = 0;
            virtual void erase() = 0;
            virtual int getScore() const = 0;
            virtual void update(ILibrary& lib, float deltaTime) = 0;
            virtual void handleEvent(const struct Event &e) = 0;
            virtual void dump(ILibrary &lib) = 0;
    };
}
```

This interface defines the core functionality required for any game. It includes methods for initialization, updating game state, handling events, and rendering.

- `init(ILibrary &lib)`: Initializes game resources using the provided library.
- `erase()`: Frees resources when the game is terminated.
- `getScore() const`: Returns the current game score.
- `update(ILibrary& lib, float deltaTime)`: Updates the game logic based on the elapsed time.
- `handleEvent(const struct Event &e)`: Processes user input and events.
- `dump(ILibrary &lib)`: Renders the game's current state using the provided library.

#### ILibrary Interface

```cpp
#pragma once

#include "Arc/Shared/Factories/IRectFactory.hpp"
#include "Arc/Shared/Factories/ISpriteFactory.hpp"
#include "Arc/Shared/Factories/ITextFactory.hpp"
#include "Arc/Shared/Factories/IMusicFactory.hpp"
#include "Arc/Shared/IDisplay.hpp"

namespace Arc::Shared {
    class ILibrary {
        public:
            virtual ~ILibrary() = default;
            virtual IDisplay &getDisplay() = 0;
            virtual Arc::Shared::Factories::IRectFactory &getRectFactory() = 0;
            virtual Arc::Shared::Factories::ISpriteFactory &getSpriteFactory() = 0;
            virtual Arc::Shared::Factories::ITextFactory &getTextFactory() = 0;
            virtual Arc::Shared::Factories::IMusicFactory &getMusicFactory() = 0;
    };
}
```

The ILibrary interface provides access to various factories and the display system. Games use this interface to create and manage visual elements and sounds.

- `getDisplay()`: Returns a reference to the display system.
- `getRectFactory()`: Returns a factory for creating rectangles.
- `getSpriteFactory()`: Returns a factory for creating sprites.
- `getTextFactory()`: Returns a factory for creating text elements.
- `getMusicFactory()`: Returns a factory for creating music elements.

#### IDisplay Interface

```cpp
#pragma once

#include <string>
#include "Arc/Shared/Models/IRect.hpp"
#include "Arc/Shared/Models/ISprite.hpp"
#include "Arc/Shared/Models/IMusic.hpp"
#include "Arc/Shared/Models/IText.hpp"
#include "Arc/Shared/Event.hpp"

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
```

The IDisplay interface handles windowing and rendering operations. It includes methods for:

- `setTitle(const std::string &title)`: Sets the window title.
- `setSize(const Vector size)`: Sets the window dimensions.
- `closeWindow()`: Closes the window.
- `draw()` methods: Renders different types of visual elements (rectangles, sprites, text).
- `playMusic()`, `stopMusic()`, `restartMusic()`: Controls music playback.
- `clear()`: Clears the screen for a new frame.
- `display()`: Updates the screen with the rendered content.
- `pollEvents(struct Event& event)`: Processes and returns pending events.
- `isOpen()`: Checks if the window is still open.

#### Event Handling

The Arcade system uses a structured event system defined in `Event.hpp`. This includes enum types for various events:

```cpp
namespace Arc::Shared {
    // General event categories
    enum EventType {
        NONE,
        MOUSE,      // Mouse-related events
        KEYBOARD,   // Keyboard-related events
        WINDOW      // Window-related events
    };

    // More specific event types...

    struct Event {
        EventType type = EventType::NONE;

        struct MouseEvent { Vector position; MouseEventType eventType; float deltaWheel; };
        struct KeyboardEvent { KeyEventType eventType; KeyCode keyCode; };
        struct WindowEvent { WindowEventType eventType; Vector size; };

        std::variant<std::monostate, MouseEvent, KeyboardEvent, WindowEvent> data;
        Event() : type(EventType::NONE), data(std::monostate{}) {}
    };
}
```

This event system allows games to receive and process user input and system events in a consistent manner across different graphical libraries.

## Implementing a Game Library

### Overview

When implementing a game library, you need to create a class that inherits from `Arc::Shared::IGame` and implement all its virtual methods. Additionally, you must provide the necessary C-style entry points for the library to be loaded properly.

### Step 1: Create Your Game Class

Start by creating a header file for your game class:

```cpp
// MyGame.hpp
#pragma once

#include "Arc/Shared/IGame.hpp"
#include "Arc/Shared/Models/IRect.hpp"
#include "Arc/Shared/LibraryType.hpp"
#include <memory>
#include <vector>

namespace Arc::Lib::Games::MyGame {
    class MyGame : public Arc::Shared::IGame {
        public:
            MyGame();
            ~MyGame() = default;

            void init(Arc::Shared::ILibrary &lib) override;
            void erase() override;
            int getScore() const override;
            void update(Arc::Shared::ILibrary &lib, float deltaTime) override;
            void handleEvent(const Arc::Shared::Event &e) override;
            void dump(Arc::Shared::ILibrary &lib) override;

        private:
            // Game-specific members and methods
            int _score;
            bool _gameOver;
            
            // Visual elements
            std::shared_ptr<Arc::Shared::Models::IText> _scoreText;
            
            // Game state methods
            void resetGame();
            void drawScore(Arc::Shared::ILibrary &lib);
    };
}
```

### Step 2: Implement Your Game Class

Next, implement the methods in a .cpp file:

```cpp
// MyGame.cpp
#include "MyGame.hpp"
#include "Arc/Shared/Event.hpp"

namespace Arc::Lib::Games::MyGame {

    MyGame::MyGame() : _score(0), _gameOver(false) {
        // Initialize game state
    }

    void MyGame::init(Arc::Shared::ILibrary &lib) {
        // Initialize visual resources
        lib.getDisplay().setSize(Arc::Shared::Vector(800, 600));
        
        // Create text for score display
        lib.getTextFactory().load("assets/MyGameAssets/font.ttf");
        _scoreText = lib.getTextFactory().create();
        _scoreText->setFontSize(24);
        _scoreText->setPos(Arc::Shared::Vector(10, 10));
        
        // Additional initialization
    }

    void MyGame::erase() {
        // Clean up resources if needed
    }

    int MyGame::getScore() const {
        return _score;
    }

    void MyGame::update(Arc::Shared::ILibrary &lib, float deltaTime) {
        if (_gameOver) {
            return;
        }
        
        // Update game state based on elapsed time
        // Example: Move objects, check collisions, etc.
    }

    void MyGame::handleEvent(const Arc::Shared::Event &e) {
        if (_gameOver) {
            // Check for restart key
            if (e.type == Arc::Shared::EventType::KEYBOARD) {
                auto keyEvent = std::get<Arc::Shared::Event::KeyboardEvent>(e.data);
                if (keyEvent.eventType == Arc::Shared::KeyEventType::K_PRESS && 
                    keyEvent.keyCode == Arc::Shared::KeyCode::K_SPACE) {
                    resetGame();
                }
            }
            return;
        }
        
        // Process player input
        if (e.type == Arc::Shared::EventType::KEYBOARD) {
            auto keyEvent = std::get<Arc::Shared::Event::KeyboardEvent>(e.data);
            if (keyEvent.eventType == Arc::Shared::KeyEventType::K_PRESS) {
                // Handle key presses for game controls
                switch (keyEvent.keyCode) {
                    case Arc::Shared::KeyCode::K_UP:
                        // Move up
                        break;
                    case Arc::Shared::KeyCode::K_DOWN:
                        // Move down
                        break;
                    // Add more key handlers
                }
            }
        }
    }

    void MyGame::dump(Arc::Shared::ILibrary &lib) {
        // Clear the screen
        lib.getDisplay().clear();
        
        // Draw game elements
        drawScore(lib);
        
        // Draw other game elements
        
        // Update the display
        lib.getDisplay().display();
    }

    void MyGame::resetGame() {
        _score = 0;
        _gameOver = false;
        // Reset other game state
    }

    void MyGame::drawScore(Arc::Shared::ILibrary &lib) {
        _scoreText->setText("Score: " + std::to_string(_score));
        lib.getDisplay().draw(*_scoreText);
    }

    // External C functions for library loading
    extern "C" {
        Arc::Shared::IGame* entryPoint() {
            return new Arc::Lib::Games::MyGame::MyGame();
        }

        const char *name() {
            return "My Game";
        }

        Arc::LibraryType::Ltype type() {
            return Arc::LibraryType::GAME;
        }
    }
}
```

### Step 3: Provide Entry Points

Every game library must export these three C functions:

1. `entryPoint()`: Returns a new instance of your game class.
2. `name()`: Returns the display name of your game.
3. `type()`: Returns the library type (GAME).

These functions allow the core system to load and instantiate your game at runtime.

### Key Requirements for Games

1. **Initialization**: Properly initialize all game resources in the `init()` method.
2. **Resource Management**: Free any allocated resources in the `erase()` method.
3. **Game Loop**: Separate logic updates (`update()`) from rendering (`dump()`).
4. **Event Handling**: Process user input in the `handleEvent()` method.
5. **Score Tracking**: Implement the `getScore()` method to provide score information.

## Implementing a Graphical Library

### Overview

A graphical library is responsible for rendering visual elements and handling user input. It must implement the `Arc::Shared::ILibrary` interface along with all required factories and display functionality.

### Step 1: Create Your Library Class

Start by creating a header file for your graphical library:

```cpp
// MyGraphics.hpp
#pragma once

#include "Arc/Shared/ILibrary.hpp"
#include "MyDisplay.hpp"
#include "Factories/MyRectFactory.hpp"
#include "Factories/MySpriteFactory.hpp"
#include "Factories/MyTextFactory.hpp"
#include "Factories/MyMusicFactory.hpp"
#include <memory>
#include "Arc/Shared/LibraryType.hpp"

namespace Arc::Libs::Graphicals::MyGraphics {
    class MyGraphicsLibrary : public Arc::Shared::ILibrary {
        public:
            MyGraphicsLibrary();
            ~MyGraphicsLibrary() = default;

            Arc::Shared::IDisplay& getDisplay() override;
            Arc::Shared::Factories::IRectFactory& getRectFactory() override;
            Arc::Shared::Factories::ISpriteFactory& getSpriteFactory() override;
            Arc::Shared::Factories::ITextFactory& getTextFactory() override;
            Arc::Shared::Factories::IMusicFactory& getMusicFactory() override;

        private:
            std::unique_ptr<MyDisplay> _display;
            std::unique_ptr<Factories::MyRectFactory> _rectFactory;
            std::unique_ptr<Factories::MySpriteFactory> _spriteFactory;
            std::unique_ptr<Factories::MyTextFactory> _textFactory;
            std::unique_ptr<Factories::MyMusicFactory> _musicFactory;
    };
}
```

### Step 2: Implement Your Library Class

Next, implement the methods in a .cpp file:

```cpp
// MyGraphics.cpp
#include "MyGraphics.hpp"

namespace Arc::Libs::Graphicals::MyGraphics {
    MyGraphicsLibrary::MyGraphicsLibrary() :
        _display(std::make_unique<MyDisplay>()),
        _rectFactory(std::make_unique<Factories::MyRectFactory>()),
        _spriteFactory(std::make_unique<Factories::MySpriteFactory>()),
        _textFactory(std::make_unique<Factories::MyTextFactory>()),
        _musicFactory(std::make_unique<Factories::MyMusicFactory>())
    {
        // Initialize your graphics library
    }

    Arc::Shared::IDisplay& MyGraphicsLibrary::getDisplay()
    {
        return *_display;
    }

    Arc::Shared::Factories::IRectFactory& MyGraphicsLibrary::getRectFactory()
    {
        return *_rectFactory;
    }

    Arc::Shared::Factories::ISpriteFactory& MyGraphicsLibrary::getSpriteFactory()
    {
        return *_spriteFactory;
    }

    Arc::Shared::Factories::ITextFactory& MyGraphicsLibrary::getTextFactory()
    {
        return *_textFactory;
    }

    Arc::Shared::Factories::IMusicFactory& MyGraphicsLibrary::getMusicFactory()
    {
        return *_musicFactory;
    }
}

// External C functions for library loading
extern "C" {
    Arc::LibraryType::Ltype type() {
        return Arc::LibraryType::GRAPHIC;
    }

    const char* name() {
        return "My Graphics";
    }

    Arc::Shared::ILibrary* entryPoint() {
        return new Arc::Libs::Graphicals::MyGraphics::MyGraphicsLibrary();
    }
}
```

### Step 3: Implement Display Class

The display class manages the window and rendering operations:

```cpp
// MyDisplay.hpp
#pragma once

#include "Arc/Shared/IDisplay.hpp"
#include "YourGraphicsLibrary.hpp" // External graphics library (SDL2, SFML, etc.)

namespace Arc::Libs::Graphicals::MyGraphics {
    class MyDisplay : public Arc::Shared::IDisplay {
        public:
            MyDisplay();
            ~MyDisplay();

            void setTitle(const std::string &title) override;
            void setSize(const Arc::Shared::Vector size) override;
            void closeWindow() override;
            void draw(const Arc::Shared::Models::IRect& rect) override;
            void draw(const Arc::Shared::Models::ISprite& sprite) override;
            void draw(const Arc::Shared::Models::IText& text) override;
            void playMusic(const Arc::Shared::Models::IMusic &music) override;
            void stopMusic(const Arc::Shared::Models::IMusic &music) override;
            void restartMusic(const Arc::Shared::Models::IMusic &music) override;
            void clear() override;
            void display() override;
            bool pollEvents(Arc::Shared::Event& event) override;
            bool isOpen() override;

        private:
            // Your window implementation and resources
            YourGraphicsLibrary::Window* _window;
            bool _isOpen;
    };
}
```

### Step 4: Implement Model Classes

You'll need to implement concrete classes for each model type (Rect, Sprite, Text, Music):

For example, a rectangle implementation:

```cpp
// MyRect.hpp
#pragma once

#include "Arc/Shared/Models/IRect.hpp"
#include "YourGraphicsLibrary.hpp"

namespace Arc::Libs::Graphicals::MyGraphics::Models {
    class MyRect : public Arc::Shared::Models::IRect {
        public:
            MyRect();
            ~MyRect() = default;

            void setSize(const Arc::Shared::Vector &size) override;
            Arc::Shared::Vector getSize() const override;
            void setPos(const Arc::Shared::Vector &pos) override;
            Arc::Shared::Vector getPos() const override;
            void setColor(const Arc::Shared::Color &color) override;
            Arc::Shared::Color &getColor() const override;
            void setOutlineColor(const Arc::Shared::Color &color) override;
            Arc::Shared::Color &getOutlineColor() const override;
            void setThickness(const int thickness) override;
            int getThickness() const override;

            // Access to native implementation
            YourGraphicsLibrary::Rectangle& getNativeRect();

        private:
            YourGraphicsLibrary::Rectangle _rectangle;
            Arc::Shared::Vector _size;
            Arc::Shared::Vector _position;
            Arc::Shared::Color _color;
            Arc::Shared::Color _outlineColor;
            int _thickness;
    };
}
```

### Step 5: Implement Factory Classes

For each model type, implement a factory:

```cpp
// MyRectFactory.hpp
#pragma once

#include "Arc/Shared/Factories/IRectFactory.hpp"
#include "../Models/MyRect.hpp"

namespace Arc::Libs::Graphicals::MyGraphics::Factories {
    class MyRectFactory : public Arc::Shared::Factories::IRectFactory {
        public:
            MyRectFactory() = default;
            ~MyRectFactory() = default;

            std::shared_ptr<Arc::Shared::Models::IRect> create() override {
                return std::make_shared<Models::MyRect>();
            }
    };
}
```

Similar factories should be implemented for sprites, text, and music.

### Step 6: Provide Entry Points

Like game libraries, graphical libraries must export three C functions:

1. `entryPoint()`: Returns a new instance of your graphics library.
2. `name()`: Returns the display name of your library.
3. `type()`: Returns the library type (GRAPHIC).

### Key Requirements for Graphical Libraries

1. **Window Management**: Properly handle window creation, event processing, and rendering.
2. **Visual Elements**: Support rendering rectangles, sprites, and text.
3. **Audio Support**: Implement basic music functionality.
4. **Event Translation**: Convert native events to Arcade's event system.
5. **Resource Management**: Handle loading and destruction of graphical and audio resources.

## Conclusion

By following this guide, you should be able to implement custom games and graphical libraries for the Arcade system. 

Remember that:
- Game libraries focus on gameplay logic and use the graphical library for rendering.
- Graphical libraries handle all rendering and input processing, abstracting away the details of the underlying graphics API.

The modular architecture of Arcade allows for great flexibility in creating different gaming experiences with various visual styles. 

## Arcade Keybinds

| Key     | Action                                         |
|---------|------------------------------------------------|
| A       | Navigate to the **previous game**              |
| Q       | Navigate to the **next game**                  |
| Z       | Navigate to the **previous graphical library** |
| S       | Navigate to the **next graphical library**     |
| F1      | **Launch the selected game**                   |
| F2      | **Switch to the selected graphical library**   |
| Escape  | **Exit** the game or the menu                  |
| N       | **Rename the player**                          |
| P       | Display the **scoreboard**                     |

### Player Management

When the player presses `N`, a prompt will appear allowing them to change their username. The username is used to identify score entries in the scoreboard.

### Scoreboard

Pressing `P` displays a list of the highest scores achieved across different games. Scores are recorded using the current username.
