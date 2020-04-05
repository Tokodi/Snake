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
    //TODO print text
}

void Button::ToggleFocus() {
    if (!_win)
        return;

    if (_isInFocus) {
        mvwchgat(_win, 1, 1, _width - 2, A_NORMAL, 1, NULL);
        _isInFocus = false;
    } else {
        mvwchgat(_win, 1, 1, _width - 2, A_BLINK, 1, NULL);
        _isInFocus = true;
    }

    Refresh();
}

} // ns Common
} // ns UI
} // ns Snake
