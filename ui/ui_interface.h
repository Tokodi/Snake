#pragma once

#include "game.h"

namespace Snake {
namespace UI {

class UIInterface {
public:
    UIInterface(unsigned int width,
                unsigned int height);

    virtual void draw() const = 0;
    virtual void handle_input() = 0;

protected:
    Model::Game _gameModel;

private:
    void handle_left_key();
    void handle_right_key();
    void handle_up_key();
    void handle_down_key();
};

} // ns UI
} // ns Snake
