/*
** EPITECH PROJECT, 2024
** OOP
** File description:
** Arcade project
*/

#include "Games/Nibbler/NibblerGame.hpp"

NibblerGame::NibblerGame()
    : _state(WIDTH, HEIGHT), _timer(0.f), _updateRate(0.15f), _hasMoved(false), _waitingForEnter(false), _highScore(0) {}

void NibblerGame::init(Arc::Shared::ILibrary &lib)
{
    lib.getDisplay().setTitle("Arcade Nibbler");
    lib.getDisplay().setSize({WIDTH * GRID_SIZE, HEIGHT * GRID_SIZE});
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void NibblerGame::erase() {}

void NibblerGame::update(Arc::Shared::ILibrary &lib, float deltaTime)
{
    (void)lib;
    _timer += deltaTime;

    if (_waitingForEnter)
        return;

    if (_timer >= _updateRate) {
        if (!_state.isLevelComplete()) {
            _state.update();

            if (_state.checkSelfCollision()) {
                const_cast<NibblerSnake &>(_state.getSnake()).setAlive(false);
            }

            if (getScore() > _highScore)
                _highScore = getScore();
        } else {
            _waitingForEnter = true;
        }

        _timer = 0.f;
        _hasMoved = false;
    }
}

void NibblerGame::handleEvent(const Arc::Shared::Event &e)
{
    if (e.type == Arc::Shared::EventType::KEYBOARD) {
        const auto &key = std::get<Arc::Shared::Event::KeyboardEvent>(e.data);
        if (key.eventType == Arc::Shared::KeyEventType::K_PRESS) {

            if (key.keyCode == Arc::Shared::KeyCode::K_R) {
                _state = NibblerGameState(WIDTH, HEIGHT);
                _waitingForEnter = false;
                _hasMoved = false;
                _timer = 0.f;
                return;
            }

            if (_waitingForEnter && key.keyCode == Arc::Shared::KeyCode::K_ENTER) {
                _state.loadNextLevel();
                _waitingForEnter = false;
                _timer = _updateRate;
                return;
            }

            if (!_waitingForEnter && !_hasMoved) {
                if (key.keyCode == Arc::Shared::KeyCode::K_UP)
                    _state.changeDirection({0, -1});
                else if (key.keyCode == Arc::Shared::KeyCode::K_DOWN)
                    _state.changeDirection({0, 1});
                else if (key.keyCode == Arc::Shared::KeyCode::K_LEFT)
                    _state.changeDirection({-1, 0});
                else if (key.keyCode == Arc::Shared::KeyCode::K_RIGHT)
                    _state.changeDirection({1, 0});
                _hasMoved = true;
            }
        }
    }
}

void NibblerGame::dump(Arc::Shared::ILibrary &lib)
{
    lib.getDisplay().clear();
    auto &rectFactory = lib.getRectFactory();

    const auto &walls = _state.getWalls();
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            if (walls[y][x]) {
                auto wall = rectFactory.create();
                wall->setSize({static_cast<float>(ENTITY_SIZE), static_cast<float>(ENTITY_SIZE)});
                wall->setPos({
                    static_cast<float>(x * GRID_SIZE + PADDING),
                    static_cast<float>(y * GRID_SIZE + PADDING)
                });
                wall->setColor({0, 0, 255, 255});
                wall->setThickness(1);
                lib.getDisplay().draw(*wall);
            }
        }
    }

    const auto &body = _state.getSnake().getBody();
    for (size_t i = 0; i < body.size(); ++i) {
        auto rect = rectFactory.create();
        rect->setSize({static_cast<float>(ENTITY_SIZE), static_cast<float>(ENTITY_SIZE)});
        rect->setPos({
            static_cast<float>(body[i].getX() * GRID_SIZE + PADDING),
            static_cast<float>(body[i].getY() * GRID_SIZE + PADDING)
        });
        rect->setColor(i == 0 ? Arc::Shared::Color{255, 165, 0, 255} : Arc::Shared::Color{0, 255, 0, 255});
        lib.getDisplay().draw(*rect);
    }

    for (const auto &fruit : _state.getFruits()) {
        auto rect = rectFactory.create();
        rect->setSize({static_cast<float>(ENTITY_SIZE), static_cast<float>(ENTITY_SIZE)});
        rect->setPos({
            static_cast<float>(fruit.getPosition().getX() * GRID_SIZE + PADDING),
            static_cast<float>(fruit.getPosition().getY() * GRID_SIZE + PADDING)
        });
        rect->setColor({255, 0, 0, 255});
        lib.getDisplay().draw(*rect);
    }

    auto &textFactory = lib.getTextFactory();
    auto scoreText = textFactory.create();
    scoreText->setText("Score: " + std::to_string(getScore()));
    scoreText->setColor({255, 255, 255, 255});
    scoreText->setPos({10.f, 10.f});
    lib.getDisplay().draw(*scoreText);

    auto levelText = textFactory.create();
    levelText->setText("Level: " + std::to_string(_state.getLevel()));
    levelText->setColor({200, 200, 255, 255});
    levelText->setPos({static_cast<float>(WIDTH * GRID_SIZE - 130), 10.f});
    lib.getDisplay().draw(*levelText);

    if (_waitingForEnter) {
        auto winText = textFactory.create();
        winText->setText("VICTOIRE GG !\nAppuie sur Entree");
        winText->setColor({255, 255, 0, 255});
        winText->setPos({
            static_cast<float>((WIDTH * GRID_SIZE) / 2 - 100),
            static_cast<float>((HEIGHT * GRID_SIZE) / 2 - 10)
        });
        lib.getDisplay().draw(*winText);
    }

    lib.getDisplay().display();
}

int NibblerGame::getScore() const
{
    return static_cast<int>(_state.getSnake().getBody().size()) - 4;
}

extern "C" Arc::Shared::IGame *entryPoint()
{
    return new NibblerGame();
}

extern "C" Arc::LibraryType::Ltype type()
{
    return Arc::LibraryType::GAME;
}

extern "C" const char *name()
{
    return "Nibbler";
}
