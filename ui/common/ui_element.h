#pragma once

#include <ncurses.h>
#include <utility>

namespace Snake {
namespace UI {
namespace Common {

class UIElement {
public:
    UIElement(std::pair<int, int> position,
              unsigned int width,
              unsigned int height);

    ~UIElement();

    void Refresh();

protected:
    WINDOW* _win;

    const std::pair<int, int> _position;

    const unsigned int _width;
    const unsigned int _height;

private:
    void Initialize();
};

} // ns Common
} // ns UI
} // ns Snake