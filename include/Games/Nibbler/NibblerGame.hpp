/*
** EPITECH PROJECT, 2024
** OOP
** File description:
** Arcade project
*/

#pragma once

#include "Shared/IGame.hpp"
#include "NibblerGameState.hpp"
#include "Shared/IGame.hpp"
#include "Shared/ILibrary.hpp"
#include "Shared/LibraryType.hpp"
#include "Shared/Event.hpp"
#include "Shared/Color.hpp"
#include <stdexcept>
#include <ctime>
#include <cstdlib>

#define WIDTH 32
#define HEIGHT 24
#define GRID_SIZE 20
#define ENTITY_SIZE 16
#define PADDING 2

class NibblerGame : public Arc::Shared::IGame {
public:
    NibblerGame();
    void init(Arc::Shared::ILibrary &lib) override;
    void erase() override;
    void update(Arc::Shared::ILibrary &lib, float deltaTime) override;
    void handleEvent(const Arc::Shared::Event &event) override;
    void dump(Arc::Shared::ILibrary &lib) override;
    int getScore() const override;

private:
    NibblerGameState _state;
    float _timer;
    float _updateRate;
    bool _hasMoved;
    bool _waitingForEnter;
    int _score = 0;
    int _highScore;
};