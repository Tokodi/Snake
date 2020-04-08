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

    void Show() override;
    void Hide() override;

    void DrawPixel(std::pair<int, int> position, int colorIndex);
    void PrintToCenter(std::string input, int row);
    int Getch() const;
};



} // ns Common
} // ns UI
} // ns Snake
