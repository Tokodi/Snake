#pragma once

#include "table.h"
#include "common_utils.h"

namespace Snake {
namespace UI {

class ViewInterface {
public:
    ViewInterface(unsigned int width,
                  unsigned int height)
        : _width(width)
        , _height(height) {};

    unsigned int GetWidth() const { return _width; }
    unsigned int GetHeight() const { return _height; }

    virtual Direction GetStartDirection() const = 0;
    virtual Direction GetUserInputNonBlocking() const = 0;

    virtual void Draw(const std::shared_ptr<const Model::Table> table) = 0;
    virtual void UpdateLifeCount(int lifeCount) = 0;
    virtual void UpdateScore(int score) = 0;

    virtual void Show() = 0;
    virtual void Hide() = 0;

protected:
    const unsigned int _width;
    const unsigned int _height;
};

} // ns UI
} // ns Snake
