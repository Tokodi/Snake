#include "ui_ncurses.h"
#include "utils.h"

using std::make_unique;
using std::shared_ptr;

using Position = std::pair<int, int>;

namespace Snake {
namespace UI {

UINcurses::UINcurses(shared_ptr<const Model::Game> gameModelPtr,
                     int posX,
                     int posY)
    : UIInterface(gameModelPtr) {
    unsigned int width = _gameModelPtr->GetTableWidth();
    unsigned int height = _gameModelPtr->GetTableHeight();
    _window = make_unique<Common::Window>(Position(posX, posY), 2 * width + 2, height + 2);
}

void UINcurses::Draw() {
    for (unsigned int x = 0; x < _gameModelPtr->GetTableWidth(); ++x) {
        for (unsigned int y = 0; y < _gameModelPtr->GetTableHeight(); ++y) {
            switch(_gameModelPtr->GetTableField(Position(x, y))) {
                case Model::FieldType::EMPTY:
                    _window->DrawPixel(Position(x + x + 1, y + 1), COLOR_BLACK_IDX);
                    break;
                case Model::FieldType::SNAKE:
                    _window->DrawPixel(Position(x + x + 1, y + 1), COLOR_GREEN_IDX);
                    break;
                case Model::FieldType::FOOD:
                    _window->DrawPixel(Position(x + x + 1, y + 1), COLOR_RED_IDX);
                    break;
            }
        }
    }

    _window->Refresh();
}

void UINcurses::HandleInput() {
    int key = getch();
    flushinp();
    switch (key) {
        case KEY_LEFT:
            HandleLeftKey();
            break;
        case KEY_RIGHT:
            HandleRightKey();
            break;
        case KEY_UP:
            HandleUpKey();
            break;
        case KEY_DOWN:
            HandleDownKey();
            break;
        case 'a':
            HandleLeftKey();
            break;
        case 'd':
            HandleRightKey();
            break;
        case 'w':
            HandleUpKey();
            break;
        case 's':
            HandleDownKey();
            break;
    }
}

} // ns UI
} // ns Snake
