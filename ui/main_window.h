#pragma once

#include "window.h"
#include "menu_window.h"
#include "game.h"

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
    void CreateCurrentScoreWindow();

    std::shared_ptr<Model::Game> _gameModel;

    std::shared_ptr<MenuWindow> _menuWindow;
    std::shared_ptr<Window> _currentScoreWindow;

    static constexpr unsigned int MENU_WINDOW_WIDTH = 35;
    static constexpr unsigned int MENU_WINDOW_HEIGHT = 15;

    static constexpr unsigned int SCORE_WINDOW_WIDTH = 15;
    static constexpr unsigned int SCORE_WINDOW_HEIGHT = 4;

    static constexpr unsigned int MAIN_PADDING = 2;
};

} // ns UI
} // ns Snake
