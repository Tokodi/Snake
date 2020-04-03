#include "snake.h"

#include <iostream>

namespace Snake {
namespace Model {

Snake::Snake(int startPosX, int startPosY)
    : _currentDirection(Direction::RIGHT),
      _isAlive(true) {
    Initialize(startPosX, startPosY);
}

void Snake::ChangeDirection(Direction direction) {
    if (!_isAlive)
        return;

    //Magic, TODO: more readable solution maybe
    if (static_cast<int>(_currentDirection) + static_cast<int>(direction) != 3) {
        _currentDirection = direction;
    }
}

void Snake::Move() {
    if (!_isAlive)
        return;

    Position newHead(_body.front());
    switch(_currentDirection) {
        case Direction::UP:
            --newHead.second;
            break;
        case Direction::LEFT:
            --newHead.first;
            break;
        case Direction::RIGHT:
            ++newHead.first;
            break;
        case Direction::DOWN:
            ++newHead.second;
            break;
    }

    _body.emplace_front(newHead);
    _body.pop_back();
}

void Snake::Grow() {
    if (!_isAlive)
        return;

    //Duplicate last element
    _body.push_back(_body.back());
}

const Position& Snake::GetHeadPosition() const {
    return _body.front();
}

const Position& Snake::GetTailPosition() const {
    return _body.back();
}

bool Snake::IsAlive() const {
    return _isAlive;
}

void Snake::DebugPrint() const {
    std::cout << "Front: (" << _body.front().first << ", " << _body.front().second << ")" << std::endl;
    std::cout << "Back: (" << _body.back().first << ", " << _body.back().second << ")" << std::endl;
    for (auto const& bodyPart : _body) {
        std::cout << "(" << bodyPart.first << ", " << bodyPart.second << ") ";
    }
    std::cout << std::endl;
}

void Snake::Initialize(int startPosX, int startPosY) {
    for (int i = 0; i < START_LENGTH; ++i) {
        _body.push_front(Position(startPosX + i, startPosY));
    }
}

} // ns Model
} // ns Snake
