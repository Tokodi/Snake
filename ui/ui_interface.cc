#include "ui_interface.h"

namespace Snake {
namespace UI {

UIInterface::UIInterface(unsigned int width,
                         unsigned int height) {
    _gameModel.Initialize(width, height);
}

void UIInterface::handle_left_key() {
    _gameModel.ChangeSnakeDirection(Model::Direction::LEFT);
}

void UIInterface::handle_right_key() {
    _gameModel.ChangeSnakeDirection(Model::Direction::RIGHT);
}

void UIInterface::handle_up_key() {
    _gameModel.ChangeSnakeDirection(Model::Direction::UP);
}

void UIInterface::handle_down_key() {
    _gameModel.ChangeSnakeDirection(Model::Direction::DOWN);
}

} // ns UI
} // ns Snake
