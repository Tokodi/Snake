#pragma once

#include "window.h"

#include <vector>
#include <memory>

namespace Snake {
namespace UI {

enum class WindowType { MENU };

class MainWindow final : public Common::Window {
public:
    MainWindow();

    void Show() final;

private:
    std::vector<std::pair<WindowType, std::shared_ptr<Common::Window>>> _windows;
    std::shared_ptr<Common::Window> _currentWindow;
};

} // ns UI
} // ns Snake
