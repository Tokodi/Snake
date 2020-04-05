#pragma once

#include "ui_element.h"

#include <string>

namespace Snake {
namespace UI {
namespace Common {

class Window : public UIElement {
public:
    Window(std::pair<int, int> position,
           unsigned int width,
           unsigned int height);

    void DrawPixel(std::pair<int, int> position, int colorIndex);
};



} // ns Common
} // ns UI
} // ns Snake
