#include "snake.h"

#include <iostream>

using std::deque;

using Position = std::pair<int, int>;

namespace Snake {
namespace Model {

Snake::Snake(int startPosX, int startPosY)
    : _currentDirection(START_DIRECTION),
      _isAlive(true) {
    Initialize(startPosX, startPosY);
}

void Snake::ChangeDirection(Direction newDirection) {
    if (!_isAlive)
        return;

    if (static_cast<int>(_currentDirection) + static_cast<int>(newDirection) != 3) {
        _currentDirection = newDirection;
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
    _trailPosition = _body.back();
    _body.pop_back();

    if (IsSelfHarm()) {
        _isAlive = false;
    }
}

void Snake::Grow() {
    if (!_isAlive)
        return;

    _body.push_front(_body.front());
}

const Position& Snake::GetHeadPosition() const {
    return _body.front();
}

const Position& Snake::GetTailPosition() const {
    return _body.back();
}

const Position& Snake::GetTrailPosition() const {
    return _trailPosition;
}

bool Snake::IsAlive() const {
    return _isAlive;
}

void Snake::DebugPrint() const {
    for (auto const& bodyPart : _body) {
        std::cout << "(" << bodyPart.first << ", " << bodyPart.second << ") ";
    }
    std::cout << std::endl;
}

void Snake::Initialize(int startPosX, int startPosY) {
    for (size_t i = 0; i < START_LENGTH; ++i) {
        _body.push_front(Position(startPosX + i, startPosY));
    }

    _trailPosition = _body.back();
}

bool Snake::IsSelfHarm() const {
    //TODO: This could surely be done better...
    int count = 0;
    const Position& head = _body.front();
    for (auto const& bodyPart : _body) {
        if (bodyPart == head) ++count;
    }

    return count == 1 ? false : true;
}

} // ns Model
} // ns Snake
