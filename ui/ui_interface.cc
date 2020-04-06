#include "ui_interface.h"

namespace Snake {
namespace UI {

UIInterface::UIInterface(unsigned int width,
                         unsigned int height) {
    _gameModel.Initialize(width, height);
}

void UIInterface::HandleLeftKey() {
    _gameModel.ChangeSnakeDirection(Model::Direction::LEFT);
}

void UIInterface::HandleRightKey() {
    _gameModel.ChangeSnakeDirection(Model::Direction::RIGHT);
}

void UIInterface::HandleUpKey() {
    _gameModel.ChangeSnakeDirection(Model::Direction::UP);
}

void UIInterface::HandleDownKey() {
    _gameModel.ChangeSnakeDirection(Model::Direction::DOWN);
}

} // ns UI
} // ns Snake
