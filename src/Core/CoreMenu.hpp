/*
** EPITECH PROJECT, 2024
** OOP
** File description:
** Arcade project
*/

#pragma once

#include <memory>
#include <vector>
#include <map>
#include "Score.hpp"
#include "IGame.hpp"
#include "ILibrary.hpp"
#include "LibraryLoader.hpp"

#define ARCADE_FONT "./assets/PixelGame.ttf"
#define GAMES_POS_X 200
#define GAMES_POS_Y 600

#define GRAPH_POS_X 600
#define GRAPH_POS_Y 600

#define PLAYER_POS_X 50
#define PLAYER_POS_Y 400

#define GAME_POS_X 150
#define GAME_POS_Y 400

#define BS_POS_X 250
#define BS_POS_Y 400

namespace Arc
{
class CoreMenu : public Shared::IGame
{
public:
    CoreMenu(std::vector<std::shared_ptr<LibraryObject>> libs, std::shared_ptr<LibraryObject> handle)
    {
        for (auto lib : libs) {
            if (lib->type() == LibraryType::GAME)
                _games.push_back(lib);
            else if (lib->type() == LibraryType::GRAPHIC)
                _graph.push_back(lib);
        }
        for (auto lib : _graph) {
            if (lib == handle)
                break;
            _graphIdx++;
        }
        _running = true;
    };
    ~CoreMenu() = default;
    void erase() {};
    int getScore() const { return 0; };
    void updateScores(const std::map<std::string, Score> &scores) { _scores = scores; };
    void update(Shared::ILibrary &lib, float deltaTime)
    {
        (void)deltaTime;
        if (_scoring == false) {
            lib.getDisplay().draw(*_arcade);
            lib.getDisplay().draw(*_name);
            for (auto item : _graphList)
                lib.getDisplay().draw(*item);
            for (auto item : _gameList)
                lib.getDisplay().draw(*item);
        } else {
            lib.getDisplay().draw(*_scoreboard);
            int space = 0;
            for (auto entry : _scores) {
                auto name = lib.getTextFactory().create();
                name->setColor(Arc::Shared::Color{255,255,255,255});
                name->setFont(ARCADE_FONT);
                name->setText(entry.second.player);
                name->setPos(Shared::Vector(PLAYER_POS_X, PLAYER_POS_Y+ space));

                auto game = lib.getTextFactory().create();
                game->setColor(Arc::Shared::Color{255,255,255,255});
                game->setFont(ARCADE_FONT);
                game->setText(entry.second.game);
                game->setPos(Shared::Vector(GAME_POS_X, GAME_POS_Y + space));

                auto bs = lib.getTextFactory().create();
                bs->setColor(Arc::Shared::Color{255,255,255,255});
                bs->setFont(ARCADE_FONT);
                bs->setText(std::to_string(entry.second.bs));
                bs->setPos(Shared::Vector(BS_POS_X, BS_POS_Y + space));

                lib.getDisplay().draw(*name);
                lib.getDisplay().draw(*game);
                lib.getDisplay().draw(*bs);

                space += 50;
            }
        }
    };
    void dump(Shared::ILibrary &lib) { lib.getDisplay().display(); };
    void init(Shared::ILibrary &lib)
    {
        if (_games.empty())
            throw std::runtime_error("No game available.");
        _gameList.clear();
        _graphList.clear();
        _arcade.reset();

        Shared::Vector windSize(1920, 1080);

        lib.getDisplay().setTitle("Arcade");
        lib.getDisplay().setSize(windSize);
        lib.getTextFactory().load(ARCADE_FONT);

        _arcade = std::shared_ptr<Arc::Shared::Models::IText>(lib.getTextFactory().create());
        _arcade->setText("ARCADE");
        _arcade->setColor(Arc::Shared::Color{255,255,255,255});
        _arcade->setPos(Arc::Shared::Vector(1920 / 2, 1080 / 2));

        _scoreboard = std::shared_ptr<Arc::Shared::Models::IText>(lib.getTextFactory().create());
        _scoreboard->setText("SCOREBOARD");
        _scoreboard->setColor(Arc::Shared::Color{255,255,255,255});
        _scoreboard->setPos(Arc::Shared::Vector(1920 / 2, 1080 / 8));

        _name = std::shared_ptr<Arc::Shared::Models::IText>(lib.getTextFactory().create());
        _name->setText(_player);
        _name->setColor(Arc::Shared::Color{255,255,255,255});
        _name->setPos(Arc::Shared::Vector(1920 / 2, 1080 / 2 - 200));

        int space = 0;
        for (auto entry : _games) {
            std::shared_ptr<Shared::Models::IText> game(lib.getTextFactory().create());
            game->setText(entry->name());
            game->setFont(ARCADE_FONT);
            game->setPos(Shared::Vector(GAMES_POS_X, GAMES_POS_Y + space));
            game->setColor(Arc::Shared::Color{255, 255, 255, 255});
            space += 50;
            _gameList.push_back(game);
        }
        _gameList[_gameIdx]->setColor(Shared::Color{0, 128, 0, 255});
        space = 0;
        for (auto entry : _graph) {
            std::shared_ptr<Shared::Models::IText> graph(lib.getTextFactory().create());
            graph->setText(entry->name());
            graph->setFont(ARCADE_FONT);
            graph->setPos(Shared::Vector(GRAPH_POS_X, GRAPH_POS_Y + space));
            graph->setColor(Arc::Shared::Color{255, 255, 255, 255});
            space += 50;
            _graphList.push_back(graph);
        }
        _graphList[_graphIdx]->setColor(Shared::Color{0, 128, 0, 255});
    };

    void onKeyPressed(Shared::Event::KeyboardEvent KeyboardEvent)
    {
        if (KeyboardEvent.eventType == Shared::K_PRESS) {
            if (KeyboardEvent.keyCode == Shared::K_N)
                _naming = !_naming;
            if (_naming) {
                if (KeyboardEvent.keyCode == Shared::K_BACKSPACE)
                    _player = this->_player.substr(0, this->_player.size() - 1);
                else if (KeyboardEvent.keyCode >= Shared::K_A && KeyboardEvent.keyCode <= Shared::K_Z && _player.size() < 10) {
                auto c = 'A' + static_cast<char>(KeyboardEvent.keyCode) - static_cast<char>(Shared::K_A);
                this->_player += c;
                }
                _name->setText(_player);
                _name->setColor(Shared::Color{0, 128, 0, 255});
                return;
            }
            if (KeyboardEvent.keyCode == Shared::K_P)
                _scoring = !_scoring;
            if (_scoring)
                return;
            _name->setColor(Arc::Shared::Color{255, 255, 255, 255});
            if (KeyboardEvent.keyCode == Shared::K_Q) {
                _gameList[_gameIdx]->setColor(Arc::Shared::Color{255, 255, 255, 255});
                _gameIdx = (_gameIdx + 1) % _games.size();
                _gameList[_gameIdx]->setColor(Shared::Color{0, 128, 0, 255});
            }
            if (KeyboardEvent.keyCode == Shared::K_S) {
                _graphList[_graphIdx]->setColor(Arc::Shared::Color{255, 255, 255, 255});
                _graphIdx = (_graphIdx + 1) % _graph.size();
                _graphList[_graphIdx]->setColor(Shared::Color{0, 128, 0, 255});
            }
            if (KeyboardEvent.keyCode == Shared::K_A) {
                _gameList[_gameIdx]->setColor(Arc::Shared::Color{255, 255, 255, 255});
                _gameIdx = (_gameIdx - 1) % _games.size();
                _gameList[_gameIdx]->setColor(Shared::Color{0, 128, 0, 255});
            }
            if (KeyboardEvent.keyCode == Shared::K_Z) {
                _graphList[_graphIdx]->setColor(Arc::Shared::Color{255, 255, 255, 255});
                _graphIdx = (_graphIdx - 1) % _graph.size();
                _graphList[_graphIdx]->setColor(Shared::Color{0, 128, 0, 255});
            }
        }
    }

    void handleEvent(const Shared::Event &e)
    {
        if (!_running)
            return;

        if (std::holds_alternative<Shared::Event::KeyboardEvent>(e.data)) {
            Shared::Event::KeyboardEvent KeyboardEvent = std::get<Shared::Event::KeyboardEvent>(e.data);
            this->onKeyPressed(KeyboardEvent);
        }
    };
    std::shared_ptr<LibraryObject> getGame() const { return _games.at(_gameIdx); };
    std::shared_ptr<LibraryObject> getGraphic() const { return _graph.at(_graphIdx); };
    bool isRunning() const { return _running; };
    void setRunning(bool running) { _running = running; };
    LibraryObject &getGame() { return *_games.at(_gameIdx); };
    const std::string &getPlayer() const { return _player; };
private:
    std::vector<std::shared_ptr<LibraryObject>> _games = {};
    std::vector<std::shared_ptr<LibraryObject>> _graph = {};
    int _gameIdx = 0;
    int _graphIdx = 0;
    bool _running = false;
    bool _naming = false;
    bool _scoring = false;
    std::string _player = "GUEST";
    std::map<std::string, Score> _scores;
    std::shared_ptr<Shared::Models::IText> _arcade;
    std::shared_ptr<Shared::Models::IText> _name;
    std::shared_ptr<Shared::Models::IText> _scoreboard;
    std::vector<std::shared_ptr<Shared::Models::IText>> _gameList;
    std::vector<std::shared_ptr<Shared::Models::IText>> _graphList;
};
} // namespace arc
