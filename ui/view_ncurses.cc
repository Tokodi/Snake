#include "utils.h"
#include "view_ncurses.h"

#include <string>

using std::string;
using Snake::UI::Common::Window;
using std::make_unique;

using Position = std::pair<int, int>;

namespace Snake {
namespace UI {

NcursesView::NcursesView(unsigned int width,
                         unsigned int height)
    : _width(width),
      _height(height) {
    Initialize();
}

unsigned int NcursesView::GetWidth() const {
    return _width;
}

unsigned int NcursesView::GetHeight() const {
    return _height;
}

Direction NcursesView::GetStartDirection() const {
    int ch;
    while (true) {
        ch = _gameWindow->Getch();
        switch (ch) {
            case KEY_LEFT:
                return Direction::LEFT;
            case KEY_RIGHT:
                return Direction::RIGHT;
            case KEY_UP:
                return Direction::UP;
            case KEY_DOWN:
                return Direction::DOWN;
            case 'a':
                return Direction::LEFT;
            case 'd':
                return Direction::RIGHT;
            case 'w':
                return Direction::UP;
            case 's':
                return Direction::DOWN;
            default:
                continue;
        }
    }
}

Direction NcursesView::GetUserInputNonBlocking() const {
    int key = getch();
    flushinp();
    switch (key) {
        case KEY_LEFT:
            return Direction::LEFT;
        case KEY_RIGHT:
            return Direction::RIGHT;
        case KEY_UP:
            return Direction::UP;
        case KEY_DOWN:
            return Direction::DOWN;
        case 'a':
            return Direction::LEFT;
        case 'd':
            return Direction::RIGHT;
        case 'w':
            return Direction::UP;
        case 's':
            return Direction::DOWN;
    }
    return Direction::NONE;
}

void NcursesView::Draw(const std::shared_ptr<const Model::Table> table) {
    for (unsigned int x = 0; x < table->GetWidth(); ++x) {
        for (unsigned int y = 0; y < table->GetHeight(); ++y) {
            switch(table->GetField(Position(x, y))) {
                case Model::FieldType::EMPTY:
                    _gameWindow->DrawPixel(Position(x + x + 1, y + 1), COLOR_BLACK_IDX);
                    break;
                case Model::FieldType::SNAKE:
                    _gameWindow->DrawPixel(Position(x + x + 1, y + 1), COLOR_GREEN_IDX);
                    break;
                case Model::FieldType::FOOD:
                    _gameWindow->DrawPixel(Position(x + x + 1, y + 1), COLOR_RED_IDX);
                    break;
            }
        }
    }
    _gameWindow->Refresh();
}

void NcursesView::UpdateScore(int score) {
    _scoreWindow->PrintToCenter("Your Score:", 1);
    _scoreWindow->PrintToCenter(std::to_string(score), 2);
}

void NcursesView::Show() {
    _gameWindow->Show();
    _scoreWindow->Show();
}

void NcursesView::Hide() {
    _gameWindow->Hide();
    _scoreWindow->Hide();
}

void NcursesView::Initialize() {
    int posX = COLS/2 - _width - 1;
    int posY = LINES/2 - _height/2 - 1;
    _gameWindow = make_unique<Window>(Position(posX, posY), 2 * _width + 2, _height + 2);

    posX = COLS/2 - SCORE_WINDOW_WIDTH/2;
    posY = LINES/2 - _height/2 - 1 - 1 - SCORE_WINDOW_HEIGHT;
    _scoreWindow = make_unique<Window>(Position(posX, posY), SCORE_WINDOW_WIDTH, SCORE_WINDOW_HEIGHT);
}

} // ns UI
} // ns Snake
