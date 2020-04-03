#include "game.h"

#include <iostream>

int main() {
    Snake::Model::Game myGame;
    myGame.Initialize(10, 10);
    while (!myGame.IsGameOver()) {
        myGame.GameLoop();
        std::cout << std::endl;
    }

    return 0;
}
