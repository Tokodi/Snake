#include "window.h"

using std::string;

using Position = std::pair<int, int>;

namespace Snake {
namespace UI {
namespace Common {

Window::Window(Position position,
               unsigned int width,
               unsigned int height)
    : UIElement(position,
                width,
                height) {
}

void Window::Show() {
    if (!_win || _isVisible)
        return;

    Refresh();
    _isVisible = true;
}

void Window::Hide() {
    if (!_win || !_isVisible)
        return;

    wclear(_win);
    _isVisible = false;
}

void Window::DrawPixel(Position position, int colorIndex) {
    if (!_win)
        return;

    wattron(_win, COLOR_PAIR(colorIndex));
    mvwaddch(_win, position.second, position.first, 'X');
    mvwaddch(_win, position.second, position.first + 1, 'X');
    wattroff(_win, COLOR_PAIR(colorIndex));
}

void Window::PrintToCenter(string input, int row) {
    int posX = _width/2 - input.length()/2;
    mvwprintw(_win, row, posX, input.c_str());
    Refresh();
}

void Window::Getch() const {
    wgetch(_win);
}

} // ns Common
} // ns UI
} // ns Snake
