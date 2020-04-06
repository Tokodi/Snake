#pragma once

#include "game.h"

namespace Snake {
namespace UI {

class UIInterface {
public:
    UIInterface(unsigned int width,
                unsigned int height);

    virtual ~UIInterface() = default;

    virtual void Draw() = 0;
    virtual void HandleInput() = 0;

protected:
    void HandleLeftKey();
    void HandleRightKey();
    void HandleUpKey();
    void HandleDownKey();

protected:
    Model::Game _gameModel;
};

} // ns UI
} // ns Snake
