#pragma once

#include <utility>

namespace Snake {
namespace Model {

class Food {
public:
    Food(int posX, int posY);

    const std::pair<int, int>& GetPosition() const;

private:
    std::pair<int, int> _position;
};

} // ns Model
} // ns Snake
