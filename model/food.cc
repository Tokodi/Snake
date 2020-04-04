#include "food.h"

using Position = std::pair<int, int>;

namespace Snake {
namespace Model {

Food::Food(Position position)
    : _position(position) {
}

const Position& Food::GetPosition() const {
    return _position;
}

} // ns Model
} // ns Snake
