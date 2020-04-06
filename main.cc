#include "ui_ncurses.h"

#include <cstdio>
#include <iostream>

int main() {
    Snake::UI::UINcurses ui(40, 40);
    ui.Draw();


    int bin;
    std::cin >> bin;

    return 0;
}
