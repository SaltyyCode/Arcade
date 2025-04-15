#pragma once

#include "Shared/IGame.hpp"
#include "Shared/ILibrary.hpp"
#include "Shared/LibraryType.hpp"
#include "Shared/Event.hpp"
#include "Shared/Color.hpp"
#include "GameState.hpp"

#include <memory>
#include <cstdlib>
#include <ctime>

static const int GRID_SIZE = 20;
static const int WIDTH = 32; 
static const int HEIGHT = 24;
static const int ENTITY_SIZE = 14;
static const int PADDING = (GRID_SIZE - ENTITY_SIZE) / 2;

class SnakeGame : public Arc::Shared::IGame {
public:
    SnakeGame();
    ~SnakeGame() override = default;

    void init(Arc::Shared::ILibrary &lib) override;
    void erase() override;
    void update(Arc::Shared::ILibrary &lib, float deltaTime) override;
    void handleEvent(const Arc::Shared::Event &e) override;
    void dump(Arc::Shared::ILibrary &lib) override;
    int getScore() const override;
    int getHighScore() const;

private:
    GameState _state;
    float _timer;
    float _updateRate;
    int _score;
    int _highScore;
    bool _hasMoved = false;
};