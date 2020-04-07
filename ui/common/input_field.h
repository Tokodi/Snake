#pragma once

#include "ui_element.h"

namespace Snake {
namespace UI {
namespace Common {

class InputField : public UIElement {
public:
    InputField(std::pair<int, int> position);

    void Show() final;
    void Hide() final;

    int GetPositiveNumber(const unsigned int maxDigits);

    static constexpr int INPUT_WINDOW_WIDTH = 30;
    static constexpr int INPUT_WINDOW_HEIGHT = 3;

private:
    void SetCursor();
    void UnSetCursor();

private:
    bool _isInFocus;
};

} // ns Common
} // ns UI
} // ns Snake
