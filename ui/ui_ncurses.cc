#include "ui_ncurses.h"
#include "utils.h"

using std::make_unique;

using Position = std::pair<int, int>;

namespace Snake {
namespace UI {

UINcurses::UINcurses(unsigned int width,
                   unsigned int height)
    : UIInterface(width,
                  height) {
    Utils::Initialize();
    _window = make_unique<Common::Window>(Position(0, 0), 2 * width + 2, height + 2);
}

UINcurses::~UINcurses() {
    Utils::Terminate();
}

void UINcurses::Draw() {
    for (unsigned int x = 0; x < _gameModel.GetTableWidth(); ++x) {
        for (unsigned int y = 0; y < _gameModel.GetTableHeight(); ++y) {
            switch(_gameModel.GetTableField(Position(x, y))) {
                case Model::FieldType::EMPTY:
                    _window->DrawPixel(Position(x + x + 1, y + 1), Utils::COLOR_BLACK_IDX);
                    break;
                case Model::FieldType::SNAKE:
                    _window->DrawPixel(Position(x + x + 1, y + 1), Utils::COLOR_GREEN_IDX);
                    break;
                case Model::FieldType::FOOD:
                    _window->DrawPixel(Position(x + x + 1, y + 1), Utils::COLOR_RED_IDX);
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
