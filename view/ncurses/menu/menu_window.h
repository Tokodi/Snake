#pragma once

#include "button.h"
#include "window.h"

#include <memory>
#include <vector>

namespace Snake {
namespace UI {

enum class StatusType { START, SCORES, EXIT };

class MenuWindow final: public Common::Window {
public:
    MenuWindow();

    void Show() final;
    void Hide() final;

    StatusType GetUserInput();

    static constexpr unsigned int MENU_WIDHT = 35;
    static constexpr unsigned int MENU_HEIGHT = 15;

private:
    void CreateButtons();
    void FocusNextButton();
    void FocusPrevButton();

    std::vector<std::pair<StatusType, std::shared_ptr<Common::Button>>> _buttons;
    std::vector<std::pair<StatusType, std::shared_ptr<Common::Button>>>::const_iterator _currentButton;
};

} // ns UI
} // ns Snake
