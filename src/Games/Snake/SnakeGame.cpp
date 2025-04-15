#include "Games/Snake/SnakeGame.hpp"


SnakeGame::SnakeGame()
    : _state(WIDTH, HEIGHT), _timer(0.f), _updateRate(0.15f), _score(0), _highScore(0) {}

void SnakeGame::init(Arc::Shared::ILibrary &lib)
{
    lib.getDisplay().setTitle("Arcade Snake");
    lib.getDisplay().setSize({WIDTH * GRID_SIZE, HEIGHT * GRID_SIZE});
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    _hasMoved = false;
}

void SnakeGame::erase() {}

void SnakeGame::update(Arc::Shared::ILibrary &lib, float deltaTime)
{
    (void)lib;

    _timer += deltaTime;

    if (_timer >= _updateRate) {
        _state.update();
        if (_state.checkCollision()) {
            Snake &snake = const_cast<Snake &>(_state.getSnake());
            snake.setAlive(false);
        }
        int score = getScore();
        if (score > _highScore)
            _highScore = score;

        _timer = 0.f;
    }
}

void SnakeGame::handleEvent(const Arc::Shared::Event &e)
{

    if (e.type == Arc::Shared::EventType::KEYBOARD) {
        const Arc::Shared::Event::KeyboardEvent &keyEvent = std::get<Arc::Shared::Event::KeyboardEvent>(e.data);
        if (keyEvent.eventType == Arc::Shared::KeyEventType::K_PRESS) {
            if (keyEvent.keyCode == Arc::Shared::KeyCode::K_UP)
                _state.changeDirection(Arc::Shared::Vector(0, -1));
            else if (keyEvent.keyCode == Arc::Shared::KeyCode::K_DOWN)
                _state.changeDirection(Arc::Shared::Vector(0, 1));
            else if (keyEvent.keyCode == Arc::Shared::KeyCode::K_LEFT)
                _state.changeDirection(Arc::Shared::Vector(-1, 0));
            else if (keyEvent.keyCode == Arc::Shared::KeyCode::K_RIGHT)
                _state.changeDirection(Arc::Shared::Vector(1, 0));
            _hasMoved = true;
        }
        if (keyEvent.keyCode == Arc::Shared::KeyCode::K_R) {
            _state = GameState(WIDTH, HEIGHT);
            _timer = 0.f;
            _hasMoved = false;
            return;
        }
    }
}

void SnakeGame::dump(Arc::Shared::ILibrary &lib)
{
    lib.getDisplay().clear();
    auto &rectFactory = lib.getRectFactory();

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            if (y == 0 || y == HEIGHT - 1 || x == 0 || x == WIDTH - 1) {
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
        if (i == 0)
            rect->setColor({139, 69, 19, 255});
        else
            rect->setColor({0, 255, 0, 255});
        lib.getDisplay().draw(*rect);
    }

    Arc::Shared::Vector fruitPos = _state.getFruit().getPosition();
    auto fruitRect = rectFactory.create();
    fruitRect->setSize({static_cast<float>(ENTITY_SIZE), static_cast<float>(ENTITY_SIZE)});
    fruitRect->setPos({
        static_cast<float>(fruitPos.getX() * GRID_SIZE + PADDING),
        static_cast<float>(fruitPos.getY() * GRID_SIZE + PADDING)
    });
    fruitRect->setColor({255, 0, 0, 255});
    lib.getDisplay().draw(*fruitRect);

    auto &textFactory = lib.getTextFactory();
    auto scoreText = textFactory.create();
    scoreText->setText("Score: " + std::to_string(getScore()));
    scoreText->setColor({255, 255, 255, 255});
    scoreText->setPos({10, 10});
    lib.getDisplay().draw(*scoreText);

    lib.getDisplay().display();
}

int SnakeGame::getScore() const
{
    return static_cast<int>(_state.getSnake().getBody().size()) - 4;
}

int SnakeGame::getHighScore() const
{
    return _highScore;
}


extern "C" Arc::Shared::IGame *entryPoint()
{
    return new SnakeGame();
}

extern "C" Arc::LibraryType::Ltype type()
{
    return Arc::LibraryType::GAME;
}

extern "C" const char *name() {
    return "Snake";
}
