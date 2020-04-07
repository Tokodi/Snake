#include "size_getter_window.h"

using std::make_unique;

using Position = std::pair<int, int>;

namespace Snake {
namespace UI {

SizeGetterWindow::SizeGetterWindow()
    :Window(Position(COLS/2 - SIZE_GETTER_WINDOW_WIDTH/2, LINES/2 - SIZE_GETTER_WINDOW_HEIGHT/2),
            SIZE_GETTER_WINDOW_WIDTH,
            SIZE_GETTER_WINDOW_HEIGHT) {
    CreateInputFields();
}

void SizeGetterWindow::Show() {
    if (!_win || _isVisible)
        return;

    Refresh();

    PrintToCenter("Table Size", 2);

    _widthInput->Show();
    _heightInput->Show();

    _isVisible = true;
}

void SizeGetterWindow::Hide() {
    if (!_win || !_isVisible)
        return;

    //TODO: HUGE BUG, IF HIDE BEFORE INPUT IS TAKEN?
    _widthInput->Hide();
    _heightInput->Hide();

    werase(_win);
    _isVisible = false;
}

int SizeGetterWindow::GetTableWidth() {
    return _widthInput->GetPositiveNumber(3);
}

int SizeGetterWindow::GetTableHeight() {
    return _heightInput->GetPositiveNumber(3);
}

void SizeGetterWindow::CreateInputFields() {
    unsigned int center = _width/2 - 5/2;
    unsigned int posY = 4;
    _widthInput = make_unique<Common::InputField>(Position(_position.first + center, _position.second + posY), 5);

    posY += 3;
    _heightInput = make_unique<Common::InputField>(Position(_position.first + center, _position.second + posY), 5);
}

} // ns UI
} // ns Snake
