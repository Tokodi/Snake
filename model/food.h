#pragma once

#include <utility>

using Position = std::pair<int, int>;

namespace Snake {
namespace Model {

class Food {
public:
    Food(int posX, int posY);

    const Position& GetPosition() const;

private:
    Position _position;
};

} // ns Model
} // ns Snake
