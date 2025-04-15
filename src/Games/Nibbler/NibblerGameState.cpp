/*
** EPITECH PROJECT, 2024
** OOP
** File description:
** Arcade project
*/

#include "Games/Nibbler/NibblerGameState.hpp"

NibblerGameState::NibblerGameState(int width, int height)
    : _width(width),
      _height(height),
      _level(1),
      _snake({static_cast<float>(width / 2), static_cast<float>(height / 2)})
{
    loadNextLevel();
}

void NibblerGameState::loadNextLevel()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)) + _level * 42);
    _level++;
    _walls.clear();
    _walls.resize(_height, std::vector<bool>(_width, false));

    for (int x = 0; x < _width; ++x) {
        _walls[0][x] = true;
        _walls[_height - 1][x] = true;
    }
    for (int y = 0; y < _height; ++y) {
        _walls[y][0] = true;
        _walls[y][_width - 1] = true;
    }

    _snake = NibblerSnake({static_cast<float>(_width / 2), static_cast<float>(_height / 2)});
    _fruits.clear();

    generateWalls(_level);
    generateLevelFruits();
}

void NibblerGameState::generateWalls(int level)
{
    int segmentCount = 10 + level * 2;

    for (int s = 0; s < segmentCount; ++s) {
        bool horizontal = std::rand() % 2;
        int length = 3 + std::rand() % 4;

        int x = std::rand() % (_width - (horizontal ? length + 2 : 2)) + 1;
        int y = std::rand() % (_height - (horizontal ? 2 : length + 2)) + 1;

        for (int i = 0; i < length; ++i) {
            int dx = horizontal ? x + i : x;
            int dy = horizontal ? y : y + i;

            if (dx >= _width / 2 - 1 && dx <= _width / 2 + 1 &&
                dy >= _height / 2 - 1 && dy <= _height / 2 + 1)
                continue;

            _walls[dy][dx] = true;
        }
    }
}

void NibblerGameState::generateLevelFruits()
{
    int fruitCount = 10;
    while (_fruits.size() < static_cast<size_t>(fruitCount)) {
        Arc::Shared::Vector pos(
            static_cast<float>(std::rand() % _width),
            static_cast<float>(std::rand() % _height)
        );

        bool isWall = isWallAt(pos);
        bool onSnake = false;
        for (const auto &part : _snake.getBody())
            if (pos == part)
                onSnake = true;
        bool alreadyFruit = false;
        for (const auto &f : _fruits)
            if (f.getPosition() == pos)
                alreadyFruit = true;

        if (!isWall && !onSnake && !alreadyFruit)
            _fruits.emplace_back(pos);
    }
}

void NibblerGameState::update()
{
    Arc::Shared::Vector nextPos = _snake.getHeadPosition() + _snake.getDirection();

    if (isWallAt(nextPos)) {
        Arc::Shared::Vector left = {_snake.getDirection().getY(), -_snake.getDirection().getX()};
        Arc::Shared::Vector right = {-_snake.getDirection().getY(), _snake.getDirection().getX()};

        if (!isWallAt(_snake.getHeadPosition() + left))
            _snake.changeDirection(left);
        else if (!isWallAt(_snake.getHeadPosition() + right))
            _snake.changeDirection(right);
        else {
            _snake.setAlive(false);
            return;
        }
    }
    _snake.move();
    checkFruitCollision();
}

void NibblerGameState::checkFruitCollision()
{
    Arc::Shared::Vector head = _snake.getHeadPosition();

    for (auto it = _fruits.begin(); it != _fruits.end(); ++it) {
        if (head == it->getPosition()) {
            _fruits.erase(it);
            _snake.grow();
            return;
        }
    }
}

bool NibblerGameState::checkSelfCollision() const
{
    Arc::Shared::Vector head = _snake.getHeadPosition();

    const auto &body = _snake.getBody();
    for (size_t i = 1; i < body.size(); ++i) {
        if (head == body[i])
            return true;
    }
    return false;
}

bool NibblerGameState::isLevelComplete() const
{
    return _fruits.empty();
}

const NibblerSnake &NibblerGameState::getSnake() const
{
    return _snake;
}

const std::vector<NibblerFruit> &NibblerGameState::getFruits() const
{
    return _fruits;
}

int NibblerGameState::getWidth() const
{
    return _width;
}
int NibblerGameState::getHeight() const
{
    return _height;
}

bool NibblerGameState::isWallAt(const Arc::Shared::Vector &pos) const
{
    int x = static_cast<int>(pos.getX());
    int y = static_cast<int>(pos.getY());

    if (x < 0 || x >= _width || y < 0 || y >= _height)
        return true;
    return _walls[y][x];
}

const std::vector<std::vector<bool>> &NibblerGameState::getWalls() const
{
    return _walls;
}

int NibblerGameState::getLevel() const
{
    return _level - 1;
}

void NibblerGameState::changeDirection(const Arc::Shared::Vector &dir)
{
    _snake.changeDirection(dir);
}