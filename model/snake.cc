#include "snake.h"

#include <iostream>

using std::deque;

using Position = std::pair<int, int>;

namespace Snake {
namespace Model {

Snake::Snake(Position position)
    : _isAlive(true) {
    Initialize(position);
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

void Snake::SetCurrentDirection(Direction direction) {
    _currentDirection = direction;
}

void Snake::ChangeDirection(Direction newDirection) {
    if (!_isAlive)
        return;

    //TODO:Magic
    if (static_cast<int>(_currentDirection) + static_cast<int>(newDirection) != 3) {
        _currentDirection = newDirection;
    }
}

unsigned int Snake::GetLength() const {
    return _body.size();
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

void Snake::Initialize(Position position) {
    _body.push_front(position);
    _trailPosition = _body.back();
}

bool Snake::IsSelfHarm() const {
    int matchCounter = 0;
    const Position& head = _body.front();
    for (auto const& bodyPart : _body) {
        if (bodyPart == head)
            ++matchCounter;
    }
    return matchCounter != 1;
}

} // ns Model
} // ns Snake
