#include "main_window.h"

using Position = std::pair<int, int>;

namespace Snake {
namespace UI {

MainWindow::MainWindow()
    : Common::Window(Position(0, 0), COLS, LINES) {
}

void MainWindow::Show() {
    if (!_win || _isVisible)
        return;

    Refresh();
    if (_currentWindow)
        _currentWindow->Show();
}

} // ns UI
} // ns Snake
