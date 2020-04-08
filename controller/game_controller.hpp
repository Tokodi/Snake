#pragma once

#include "game.h"
#include "utils.h"

#include <chrono>
#include <thread>

namespace Snake {
namespace Controller {

template <class View>
class GameController {
public:
    GameController() {};

    void StartGame(int width, int height);

private:
    void SetStartDirection(const UI::Direction direction);
    void HandleUserInput(const UI::Direction direction);

private:
    std::shared_ptr<View> _view;
    Model::Game _gameModel;
};

template <class View>
void GameController<View>::StartGame(int width, int height) {
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
    _view->Hide();
}

template <class View>
void GameController<View>::SetStartDirection(UI::Direction direction) {
    switch (direction) {
        case UI::Direction::LEFT:
            _gameModel.SetSnakeDirection(Model::Direction::LEFT);
            break;
        case UI::Direction::RIGHT:
            _gameModel.SetSnakeDirection(Model::Direction::RIGHT);
            break;
        case UI::Direction::UP:
            _gameModel.SetSnakeDirection(Model::Direction::UP);
            break;
        case UI::Direction::DOWN:
            _gameModel.SetSnakeDirection(Model::Direction::DOWN);
            break;
        default:
            break;
    }
}

template <class View>
void GameController<View>::HandleUserInput(UI::Direction direction) {
    switch (direction) {
        case UI::Direction::LEFT:
            _gameModel.ChangeSnakeDirection(Model::Direction::LEFT);
            break;
        case UI::Direction::RIGHT:
            _gameModel.ChangeSnakeDirection(Model::Direction::RIGHT);
            break;
        case UI::Direction::UP:
            _gameModel.ChangeSnakeDirection(Model::Direction::UP);
            break;
        case UI::Direction::DOWN:
            _gameModel.ChangeSnakeDirection(Model::Direction::DOWN);
            break;
        default:
            break;
    }
}

} // ns Controller
} // ns Snake
