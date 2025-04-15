/*
** EPITECH PROJECT, 2024
** OOP
** File description:
** Arcade project
*/

#pragma once

#include <exception>
#include <string>
#include <fstream>
#include <map>
#include <memory>
#include "CoreMenu.hpp"
#include "Score.hpp"
#include "IGame.hpp"
#include "LibraryLoader.hpp"
#include "ILibrary.hpp"

#define SCORES_FILE ".scores"
namespace Arc
{

class CoreException : public std::exception
{
public:
    CoreException(const std::string &msg) : _msg(msg) {};
    ~CoreException() = default;
    virtual const char *what() const noexcept { return _msg.c_str(); }
private:
    std::string _msg;
};

class Core
{
public:
    Core(const std::string &path, bool tty) : _libLoader(LibraryLoader("./lib", tty))
    {
        _graphLibHandle = _libLoader.load(path, LibraryType::GRAPHIC);
        if (_graphLibHandle == nullptr)
            throw CoreException("File " + path + " can't be loaded.");
        _graphlib = _graphLibHandle->get<Shared::ILibrary>();
        if (_graphlib == nullptr)
            throw CoreException("cannot load graphical lib symbol entrypoint from.");
        _menu = std::make_shared<CoreMenu>(_libLoader.getLibs(), _graphLibHandle);
        _game = std::static_pointer_cast<Shared::IGame>(_menu);

        std::ifstream rstream(SCORES_FILE);
        if (!rstream.is_open())
            return;
        std::string tmp;
        while (std::getline(rstream, tmp)) {
            if (tmp.empty())
                break;
            Score score;
            tmp >> score;
            _scores[score.game] = score;
        }
        rstream.close();
        _menu->updateScores(_scores);
    };
    ~Core()
    {
        _game = nullptr;
        _menu = nullptr;
        _graphlib = nullptr;
    };

    void start_game()
    {
        _game = _menu->getGame().get<Shared::IGame>();
        _menu->setRunning(false);
        _game->init(*_graphlib);
    };
    void end_game()
    {
        if (_menu->isRunning() == true)
            _close = true;
        this->saveScore();
        _menu->updateScores(_scores);
        _game->erase();
        _menu->setRunning(true);
        _game = std::static_pointer_cast<Shared::IGame>(_menu);
        _game->init(*_graphlib); 

    };
    void switch_graphicLib()
    {
        if (_menu->getGraphic() == _graphLibHandle)
            return;
        _graphLibHandle = _menu->getGraphic();
        _graphlib = _graphLibHandle->get<Shared::ILibrary>();
        if (_graphlib == nullptr)
            throw CoreException("cannot load graphical lib symbol entrypoint from.");
        _game->erase();
        _game->init(*_graphlib);
    };
    void run()
    {
        Shared::Event event;
        auto lastTime = std::chrono::high_resolution_clock::now();
        _game->init(*_graphlib);

        while (_graphlib->getDisplay().isOpen()) {
            if (_close)
                break;

            auto currentTime = std::chrono::high_resolution_clock::now();
            std::chrono::duration<float> delta = currentTime - lastTime;
            float deltaTime = delta.count();
            lastTime = currentTime;
            _graphlib->getDisplay().clear();

            while (_graphlib->getDisplay().pollEvents(event)) {
                _game->handleEvent(event);
                if (event.type == Arc::Shared::EventType::KEYBOARD &&
                    std::holds_alternative<Arc::Shared::Event::KeyboardEvent>(event.data)) {

                    const auto &KeyboardEvent = std::get<Arc::Shared::Event::KeyboardEvent>(event.data);

                    if (KeyboardEvent.eventType == Arc::Shared::KeyEventType::K_PRESS) {
                        switch (KeyboardEvent.keyCode) {
                            case Shared::K_F1:
                                if (_menu->isRunning())
                                    start_game();
                                break;
                            case Shared::K_ESCAPE:
                                end_game();
                                break;
                            case Shared::K_F2:
                                switch_graphicLib();
                                break;
                            default:
                                break;
                        }
                    }
                }

                if (event.type == Arc::Shared::EventType::MOUSE &&
                    std::holds_alternative<Arc::Shared::Event::MouseEvent>(event.data)) {
                    continue;
                }
            }

            _game->update(*_graphlib, deltaTime);
            _game->dump(*_graphlib);
        }
    };

private:
    LibraryLoader _libLoader;
    std::shared_ptr<CoreMenu> _menu = nullptr;
    std::shared_ptr<Shared::IGame> _game = nullptr;
    std::shared_ptr<Shared::ILibrary> _graphlib = nullptr;
    std::shared_ptr<LibraryObject> _graphLibHandle = nullptr;
    std::shared_ptr<LibraryObject> _gameLibHandle = nullptr;
    bool _close = false;
    void saveScore()
    {
        std::ofstream stream(SCORES_FILE);

        if (!stream.is_open())
            return;
        if (_scores.contains(_menu->getGame().name()) || _scores[_menu->getGame().name()].bs < this->_game->getScore())
            _scores[_menu->getGame().name()] = {_menu->getGame().name(), _menu->getPlayer(), _game->getScore()};
        for (auto entry : _scores)
            stream << entry.second;
        stream.close();
    };
    std::map<std::string, Arc::Score> _scores;
};
} // namespace arc
