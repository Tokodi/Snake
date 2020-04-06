#include "ui_interface.h"

using std::shared_ptr;

namespace Snake {
namespace UI {

UIInterface::UIInterface(shared_ptr<Model::Game> gameModelPtr)
    : _gameModelPtr(gameModelPtr) {
}

void UIInterface::HandleLeftKey() {
    _gameModelPtr->ChangeSnakeDirection(Model::Direction::LEFT);
}

void UIInterface::HandleRightKey() {
    _gameModelPtr->ChangeSnakeDirection(Model::Direction::RIGHT);
}

void UIInterface::HandleUpKey() {
    _gameModelPtr->ChangeSnakeDirection(Model::Direction::UP);
}

void UIInterface::HandleDownKey() {
    _gameModelPtr->ChangeSnakeDirection(Model::Direction::DOWN);
}

} // ns UI
} // ns Snake
