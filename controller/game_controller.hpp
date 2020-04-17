#pragma once

#include "game.h"
#include "common_utils.h"

#include <chrono>
#include <thread>

namespace Snake {
namespace Controller {

template <class View, class Persistence>
class GameController {
public:
    GameController() {};

    void StartGame(int width, int height);

private:
    void SetStartDirection(const Direction direction);
    void HandleUserInput(const Direction direction);

private:
    //TODO: set username accordingly
    std::string _userName = "Test User";

    Model::Game _gameModel;
    Persistence _persistence;
    std::shared_ptr<View> _view;
};

template <class View, class Persistence>
void GameController<View, Persistence>::StartGame(int width, int height) {
    _view.reset();
    _view = std::make_shared<View>(width, height);
    _gameModel.NewGame(width, height);
    while (!_gameModel.IsGameOver()) {
        _gameModel.NewRound();
        _view->Show();
        _view->UpdateScore(_gameModel.GetScore());
        _view->UpdateLifeCount(_gameModel.GetLifeCounter());
        _view->Draw(_gameModel.GetTable());
        SetStartDirection(_view->GetStartDirection());
        while (!_gameModel.IsRoundOver()) {
            HandleUserInput(_view->GetUserInputNonBlocking());
            _gameModel.StepGame();
            _view->UpdateScore(_gameModel.GetScore());
            _view->Draw(_gameModel.GetTable());
            _view->UpdateScore(_gameModel.GetScore());
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        _view->UpdateLifeCount(_gameModel.GetLifeCounter());
    }
    _persistence.SaveScore(_userName, _gameModel.GetScore());
    _view->Hide();
}

template <class View, class Persistence>
void GameController<View, Persistence>::SetStartDirection(Direction direction) {
    switch (direction) {
        case Direction::LEFT:
            _gameModel.SetSnakeDirection(Model::Direction::LEFT);
            break;
        case Direction::RIGHT:
            _gameModel.SetSnakeDirection(Model::Direction::RIGHT);
            break;
        case Direction::UP:
            _gameModel.SetSnakeDirection(Model::Direction::UP);
            break;
        case Direction::DOWN:
            _gameModel.SetSnakeDirection(Model::Direction::DOWN);
            break;
        default:
            break;
    }
}

template <class View, class Persistence>
void GameController<View, Persistence>::HandleUserInput(Direction direction) {
    switch (direction) {
        case Direction::LEFT:
            _gameModel.ChangeSnakeDirection(Model::Direction::LEFT);
            break;
        case Direction::RIGHT:
            _gameModel.ChangeSnakeDirection(Model::Direction::RIGHT);
            break;
        case Direction::UP:
            _gameModel.ChangeSnakeDirection(Model::Direction::UP);
            break;
        case Direction::DOWN:
            _gameModel.ChangeSnakeDirection(Model::Direction::DOWN);
            break;
        default:
            break;
    }
}

} // ns Controller
} // ns Snake
