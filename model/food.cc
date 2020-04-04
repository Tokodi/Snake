#include "food.h"

using Position = std::pair<int, int>;

namespace Snake {
namespace Model {

Food::Food(int posX, int posY)
    : _position(posX, posY) {
}

const Position& Food::GetPosition() const {
    return _position;
}

} // ns Model
} // ns Snake
