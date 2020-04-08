#pragma once

#include <deque>

namespace Snake {
namespace Model {

enum class Direction { UP, LEFT, RIGHT, DOWN };

class Snake {
public:
    Snake(std::pair<int, int> position);

    void Move();
    void Grow();

    void SetCurrentDirection(Direction direction);
    void ChangeDirection(Direction direction);

    unsigned int GetLength() const;

    const std::pair<int, int>& GetHeadPosition() const;
    const std::pair<int, int>& GetTailPosition() const;
    const std::pair<int, int>& GetTrailPosition() const;

    bool IsAlive() const;

    void DebugPrint() const;

private:
    void Initialize(std::pair<int, int> position);
    bool IsSelfHarm() const;

private:
    Direction _currentDirection;
    bool _isAlive;

    std::deque<std::pair<int, int>> _body;
    std::pair<int, int> _trailPosition;
};

} // ns Model
} // ns Snake
