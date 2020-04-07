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
    MenuWindow(std::pair<int, int> position,
               unsigned int width,
               unsigned int height);

    void Show() override;

    StatusType GetUserInput();

private:
    void CreateButtons();
    void FocusNextButton();

    std::vector<std::pair<StatusType, std::shared_ptr<Common::Button>>> _buttons;
    std::vector<std::pair<StatusType, std::shared_ptr<Common::Button>>>::const_iterator _currentButton;
};

} // ns UI
} // ns Snake
