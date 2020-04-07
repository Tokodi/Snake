#include "input_field.h"

#include <string>

using Position = std::pair<int, int>;
using std::string;

namespace Snake {
namespace UI {
namespace Common {

InputField::InputField(Position position)
    : UIElement(position,
                INPUT_WINDOW_WIDTH,
                INPUT_WINDOW_HEIGHT),
      _isInFocus(false) {
}

void InputField::Show() {
    if (!_win || _isVisible)
        return;

    Refresh();

    _isVisible = true;
}

void InputField::Hide() {
    if (!_win || !_isVisible)
        return;

    werase(_win);

    _isVisible = false;
}

int InputField::GetPositiveNumber(const unsigned int maxDigits) {
    SetCursor();

    string input;
    int ch;

    while (((ch = wgetch(_win)) != '\n') && (input.length() != maxDigits)) {
        input.push_back(ch);
    }

    UnSetCursor();

    return std::stoi(input);
}

void InputField::SetCursor() {
    echo();
    curs_set(1);
    wmove(_win, 1, 1);
}

void InputField::UnSetCursor() {
    noecho();
    curs_set(0);
}

} // ns Common
} // ns UI
} // ns Snake
