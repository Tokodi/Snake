#include "menu_window.h"

using std::make_shared;
using std::shared_ptr;
using std::make_pair;

using Position = std::pair<int, int>;

namespace Snake {
namespace UI {

MenuWindow::MenuWindow(Position position,
                       unsigned int width,
                       unsigned int height)
    : Window(position,
             width,
             height) {
    CreateButtons();
}

void MenuWindow::Show() {
    if (!_win || _isVisible)
        return;

    //PrintTitle();
    Refresh();

    for (auto const& button : _buttons) {
        button.second->Show();
    }

    _currentButton = _buttons.cbegin();
    _currentButton->second->ToggleFocus();

    _isVisible = true;
}

void MenuWindow::Hide() {
    if (!_win || !_isVisible)
        return;

    _currentButton->second->ToggleFocus();

    for (auto const& button : _buttons) {
        button.second->Hide();
    }

    werase(_win);

    _isVisible = false;
}

StatusType MenuWindow::GetUserInput() {
    int ch;
    while ((ch = wgetch(_win)) != 10) {
        if (ch == 9) // TODO: Get a working macro for this...
            FocusNextButton();
    }

    return _currentButton->first;
}

void MenuWindow::CreateButtons() {
    uint32_t center = _width/2 - Common::Button::BUTTON_WIDTH/2;
    uint32_t posY = 4; //TODO: remove magic constants
    _buttons.push_back(
            make_pair<StatusType, shared_ptr<Common::Button>>(
                StatusType::START, make_shared<Common::Button>(Position(_position.first + center, _position.second + posY), "Start")
            ));

    posY += 3;
    _buttons.push_back(
            make_pair<StatusType, shared_ptr<Common::Button>>(
                StatusType::SCORES, make_shared<Common::Button>(Position(_position.first + center, _position.second + posY), "High scores")
            ));

    posY += 3;
    _buttons.push_back(
            make_pair<StatusType, shared_ptr<Common::Button>>(
                StatusType::EXIT, make_shared<Common::Button>(Position(_position.first + center, _position.second + posY), "Exit")
            ));
}

void MenuWindow::FocusNextButton() {
    _currentButton->second->ToggleFocus();
    if (++_currentButton == _buttons.cend()) {
        _currentButton = _buttons.cbegin();
    }
    _currentButton->second->ToggleFocus();
}

} // ns UI
} // ns Snake
