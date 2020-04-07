#include "main_window.h"

using std::make_shared;

using Position = std::pair<int, int>;

namespace Snake {
namespace UI {

MainWindow::MainWindow()
    : Common::Window(Position(0, 0), COLS, LINES) {
    CreateWindows();
}

void MainWindow::StartMenuLoop() {
    Show();

    StatusType _currentStatus;
    while (true) {
        _menuWindow->Show();
        _currentStatus = _menuWindow->GetUserInput();

        switch (_currentStatus) {
            case StatusType::START:
                break;
            case StatusType::SCORES:
                break;
            case StatusType::EXIT:
                return;
                break;
        }
    }
}

void MainWindow::CreateWindows() {
    CreateMenuWindow();
}

void MainWindow::CreateMenuWindow() {
    if (_menuWindow)
        return;

    int posX = _width/2 - MENU_WINDOW_WIDTH/2;
    int posY = _height/2 - MENU_WINDOW_HEIGHT/2;
    _menuWindow = make_shared<MenuWindow>(Position(posX, posY), MENU_WINDOW_WIDTH, MENU_WINDOW_HEIGHT);
}



} // ns UI
} // ns Snake
