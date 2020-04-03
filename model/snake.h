#pragma once

#include <deque>

using Position = std::pair<int, int>;
using SnakeIterator = std::deque<Position>::const_iterator;

namespace Snake {
namespace Model {

enum class Direction { UP, LEFT, RIGHT, DOWN };

class Snake {
public:
    Snake(int startPosX, int startPosY);

    void ChangeDirection(Direction direction);
    void Move();
    void Grow();

    bool IsSelfHarm() const;

    const Position& GetHeadPosition() const;
    const Position& GetTailPosition() const;
    const Position& GetTrailPosition() const;

    bool IsAlive() const;

    //TODO: remove
    void DebugPrint() const;

private:
    void Initialize(int startPosX, int startPosY);

    Direction _currentDirection;
    bool _isAlive;

    std::deque<Position> _body;
    Position _trailPosition;

    static constexpr unsigned int START_LENGTH = 2;
    static constexpr Direction START_DIRECTION = Direction::RIGHT;
};

} // ns Model
} // ns Snake
