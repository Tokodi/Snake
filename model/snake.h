#pragma once

#include <deque>

namespace Snake {
namespace Model {

enum class Direction { UP, LEFT, RIGHT, DOWN };

class Snake {
public:
    Snake(std::pair<int, int> position);

    void SetCurrentDirection(Direction direction);
    void ChangeDirection(Direction newDirection);
    void Move();
    void Grow();

    unsigned int GetLength() const;

    const std::pair<int, int>& GetHeadPosition() const;
    const std::pair<int, int>& GetTailPosition() const;
    const std::pair<int, int>& GetTrailPosition() const;

    bool IsAlive() const;

    void DebugPrint() const;

private:
    void Initialize(std::pair<int, int> position);
    bool IsSelfHarm() const;

    Direction _currentDirection;
    bool _isAlive;

    std::deque<std::pair<int, int>> _body;
    std::pair<int, int> _trailPosition;

    static constexpr Direction START_DIRECTION = Direction::RIGHT;
};

} // ns Model
} // ns Snake
