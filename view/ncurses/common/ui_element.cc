#include "ui_element.h"

using Position = std::pair<int, int>;

namespace Snake {
namespace UI {
namespace Common {

UIElement::UIElement(Position position,
                     unsigned int width,
                     unsigned int height)
    : _position(position),
      _width(width),
      _height(height),
      _isVisible(false) {
    _win = newwin(_height, _width, _position.second, _position.first);
}

UIElement::~UIElement() {
    if (_win)
        delwin(_win);
}

void UIElement::Refresh() {
    if (!_win)
        return;

    box(_win, 0, 0);
    wrefresh(_win);
}

unsigned int UIElement::GetWidth() const {
    return _width;
}

unsigned int UIElement::GetHeight() const {
    return _height;
}

} // ns Common
} // ns UI
} // ns Snake
