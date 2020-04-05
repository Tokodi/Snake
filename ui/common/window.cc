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

void Window::DrawPixel(Position position, int colorIndex) {
    if (!_win)
        return;

    wattron(_win, COLOR_PAIR(colorIndex));
    mvwaddch(_win, position.second, position.first, 'X');
    mvwaddch(_win, position.second, position.first + 1, 'X');
    wattroff(_win, COLOR_PAIR(colorIndex));
}

} // ns Common
} // ns UI
} // ns Snake
