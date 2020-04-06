#include "ui_ncurses.h"
#include "game.h"
#include "utils.h"
#include "main_window.h"
#include "menu_window.h"

#include <chrono>
#include <thread>
#include <iostream>

int main() {
    Snake::UI::Utils::Initialize();
//    std::shared_ptr<Snake::Model::Game> gameModel = std::make_shared<Snake::Model::Game>();
//    gameModel->Initialize(40, 40);
//
//    Snake::UI::UINcurses ui(gameModel, 0, 0);
//
//    while (!gameModel->IsGameOver()) {
//        ui.HandleInput();
//        ui.Draw();
//        gameModel->StepGame();
//        std::this_thread::sleep_for(std::chrono::milliseconds(100));
//    }

//    Snake::UI::MainWindow mainWindow;
//    mainWindow.Show();

    Snake::UI::MenuWindow menuWindow(std::make_pair<int, int>(0, 0), 35, 15);
    menuWindow.Show();
    if (menuWindow.GetUserInput() == Snake::UI::StatusType::EXIT) {
        Snake::UI::Utils::Terminate();
        return -1;
    }

    int ch;
    std::cin >> ch;

    Snake::UI::Utils::Terminate();

    return 0;
}
