#include "input_field.h"

#include <string>
#include <iostream>

using Position = std::pair<int, int>;
using std::string;

namespace Snake {
namespace UI {
namespace Common {

InputField::InputField(Position position, int width)
    : UIElement(position,
                width,
                INPUT_WINDOW_HEIGHT) {
    keypad(_win, TRUE);
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
    int currentCharIndex = 1;

    //TODO: ugly AF
    while ((input.length() != maxDigits) && ((ch = wgetch(_win)) != '\n')) {
        if (!std::isdigit(ch))
            continue;

        char chArray[2];
        chArray[0] = (char)ch;
        chArray[1] = '\0';
        mvwprintw(_win, 1, currentCharIndex, chArray);
        Refresh();
        ++currentCharIndex;
        input.push_back(ch);
    }

    UnSetCursor();

    return std::stoi(input);
}

void InputField::SetCursor() {
    curs_set(1);
    wmove(_win, 1, 1);
}

void InputField::UnSetCursor() {
    curs_set(0);
}

} // ns Common
} // ns UI
} // ns Snake
