#pragma once

#include "table.h"

namespace Snake {
namespace UI {

enum class Direction { NONE, LEFT, RIGHT, UP, DOWN };

class ViewInterface {
public:
    virtual unsigned int GetWidth() const = 0;
    virtual unsigned int GetHeight() const = 0;

    virtual void GetUserRedyChar() const = 0;
    virtual Direction GetUserInputNonBlocking() const = 0;

    virtual void Draw(const std::shared_ptr<const Model::Table> table) = 0;
    virtual void UpdateScore(int score) = 0;

    virtual void Show() = 0;
    virtual void Hide() = 0;
};

} // ns UI
} // ns Snake
