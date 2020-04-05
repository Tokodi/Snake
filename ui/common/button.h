#pragma once

#include "ui_element.h"

#include <string>

namespace Snake {
namespace UI {
namespace Common {

class Button : public UIElement {
public:
    Button(std::pair<int, int> position,
           std::string text);

    void ToggleFocus();

private:
    static constexpr int BUTTON_WIDTH = 20;
    static constexpr int BUTTON_HEIGHT = 3;

    const std::string _text;
    bool _isInFocus;
};

} // ns Common
} // ns UI
} // ns Snake
