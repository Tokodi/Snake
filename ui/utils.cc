#include "utils.h"

#include <ncurses.h>
#include <iostream>

using std::cout;
using std::endl;

namespace Snake {
namespace UI {

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
    init_pair(COLOR_BLINK_IDX, COLOR_WHITE, COLOR_BLACK);
}

void Terminate() {
    endwin();
}

void Refresh() {
    refresh();
}

void Clear() {
    clear();
    Refresh();
}

} // ns UI
} // ns Snake
