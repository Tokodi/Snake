#pragma once

#include "window.h"
#include "menu_window.h"

#include <memory>

namespace Snake {
namespace UI {

enum class WindowType { MENU };

class MainWindow final : public Common::Window {
public:
    MainWindow();

    void StartMenuLoop();

private:
    void CreateWindows();
    void CreateMenuWindow();

    std::shared_ptr<Common::Window> _currentWindow;
    std::shared_ptr<MenuWindow> _menuWindow;

    static constexpr unsigned int MENU_WINDOW_WIDTH = 35;
    static constexpr unsigned int MENU_WINDOW_HEIGHT = 15;
};

} // ns UI
} // ns Snake
