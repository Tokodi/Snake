#include "button.h"

using std::string;

using Position = std::pair<int, int>;

namespace Snake {
namespace UI {
namespace Common {

Button::Button(Position position,
               string text)
    : UIElement(position,
                BUTTON_WIDTH,
                BUTTON_HEIGHT),
      _text(text),
      _isInFocus(false) {
}

void Button::Show() {
    if (!_win || _isVisible)
        return;

    int center = _width/2 - _text.length()/2;
    mvwprintw(_win, 1, center, _text.c_str());

    Refresh();

    _isVisible = true;
}

void Button::Hide() {
    if (!_win || !_isVisible)
        return;

    werase(_win);

    _isVisible = false;
}

void Button::ToggleFocus() {
    if (!_win || !_isVisible)
        return;

    if (_isInFocus) {
        mvwchgat(_win, 1, 1, _width - 2, A_NORMAL, 4, NULL);
        _isInFocus = false;
    } else {
        mvwchgat(_win, 1, 1, _width - 2, A_BLINK, 4, NULL);
        _isInFocus = true;
    }

    Refresh();
}

} // ns Common
} // ns UI
} // ns Snake
