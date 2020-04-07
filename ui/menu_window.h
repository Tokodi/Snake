#pragma once

#include "window.h"
#include "button.h"

#include <memory>
#include <vector>

namespace Snake {
namespace UI {

enum class StatusType { START, SCORES, EXIT };

class MenuWindow : public Common::Window {
public:
    MenuWindow();

    void Show() override;
    void Hide() override;

    StatusType GetUserInput();

private:
    static constexpr unsigned int MENU_WIDHT = 35;
    static constexpr unsigned int MENU_HEIGHT = 15;

    void CreateButtons();
    void FocusNextButton();

    std::vector<std::pair<StatusType, std::shared_ptr<Common::Button>>> _buttons;
    std::vector<std::pair<StatusType, std::shared_ptr<Common::Button>>>::const_iterator _currentButton;
};

} // ns UI
} // ns Snake
