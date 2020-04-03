#pragma once

#include <deque>

namespace Snake {
namespace Model {

using Position = std::pair<int, int>;

enum class Direction { UP, LEFT, RIGHT, DOWN };

class Snake {
public:
    Snake(int startPosX, int startPosY);

    void ChangeDirection(Direction direction);
    void Move();
    void Grow();

    const Position& GetHeadPosition() const;
    const Position& GetTailPosition() const;

    bool IsAlive() const;

    //TODO: remove
    void DebugPrint() const;

private:
    void Initialize(int startPosX, int startPosY);

    Direction _currentDirection;
    bool _isAlive;

    std::deque<Position> _body;

    static constexpr unsigned int START_LENGTH = 2;
};

} // ns Model
} // ns Snake
