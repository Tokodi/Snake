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

    //TODO: use final at more places
    void Show() final;

    void ToggleFocus();

    static constexpr int BUTTON_WIDTH = 20;
    static constexpr int BUTTON_HEIGHT = 3;

private:
    const std::string _text;
    bool _isInFocus;
};

} // ns Common
} // ns UI
} // ns Snake
