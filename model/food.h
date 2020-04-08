#pragma once

#include <utility>

namespace Snake {
namespace Model {

class Food {
public:
    Food(std::pair<int, int> position);

    const std::pair<int, int>& GetPosition() const;

private:
    const std::pair<int, int> _position;
};

} // ns Model
} // ns Snake
