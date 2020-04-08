#pragma once

#include "ui_element.h"

namespace Snake {
namespace UI {
namespace Common {

class InputField : public UIElement {
public:
    InputField(std::pair<int, int> position, int width);

    void Show() override;
    void Hide() override;

    int GetPositiveNumber(const unsigned int maxDigits);

    static constexpr int INPUT_WINDOW_HEIGHT = 3;

private:
    void SetCursor();
    void UnSetCursor();
};

} // ns Common
} // ns UI
} // ns Snake
