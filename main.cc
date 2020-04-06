#include "ui_ncurses.h"
#include "game.h"
#include "utils.h"

#include <chrono>
#include <thread>

int main() {
    Snake::UI::Utils::Initialize();
    std::shared_ptr<Snake::Model::Game> gameModel = std::make_shared<Snake::Model::Game>();
    gameModel->Initialize(40, 40);

    Snake::UI::UINcurses ui(gameModel, 0, 0);

    while (!gameModel->IsGameOver()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        ui.Draw();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        gameModel->StepGame();
        ui.HandleInput();
    }

    Snake::UI::Utils::Terminate();

    return 0;
}
