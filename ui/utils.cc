#include "utils.h"

#include <ncurses.h>
#include <iostream>

using std::cout;
using std::endl;

namespace Snake {
namespace UI {

static constexpr int COLOR_BLACK_IDX = 0;
static constexpr int COLOR_GREEN_IDX = 1;
static constexpr int COLOR_RED_IDX = 2;

void Initialize() {
    initscr();
    cbreak();
    noecho();
    timeout(0);
    curs_set(0);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);

    if (!has_colors()) {
        endwin();
        cout << "Your terminal does not support colors!" << endl;
        exit(1);
    }

    start_color();
    init_pair(COLOR_BLACK_IDX, COLOR_BLACK, COLOR_BLACK);
    init_pair(COLOR_RED_IDX, COLOR_RED, COLOR_RED);
    init_pair(COLOR_GREEN_IDX, COLOR_GREEN, COLOR_GREEN);
}

void Terminate() {
    endwin();
}

} // ns UI
} // ns Snake
