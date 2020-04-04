#pragma once

#include <deque>

namespace Snake {
namespace Model {

enum class Direction { UP, LEFT, RIGHT, DOWN };

class Snake {
public:
    Snake(int startPosX, int startPosY);

    void ChangeDirection(Direction direction);
    void Move();
    void Grow();

    const std::pair<int, int>& GetHeadPosition() const;
    const std::pair<int, int>& GetTailPosition() const;
    const std::pair<int, int>& GetTrailPosition() const;

    bool IsAlive() const;

    void DebugPrint() const;

private:
    void Initialize(int startPosX, int startPosY);
    bool IsSelfHarm() const;

    Direction _currentDirection;
    bool _isAlive;

    std::deque<std::pair<int, int>> _body;
    std::pair<int, int> _trailPosition;

    static constexpr unsigned int START_LENGTH = 2;
    static constexpr Direction START_DIRECTION = Direction::RIGHT;
};

} // ns Model
} // ns Snake
