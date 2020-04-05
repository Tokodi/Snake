#include "game.h"
#include "window.h"
#include "utils.h"

#include <cstdio>
#include <iostream>

int main() {
    Snake::UI::Initialize();

    Snake::UI::Common::Window myWindow(std::make_pair(0, 0), 120, 60);

    Snake::Model::Game myGame;
    myGame.Initialize(60, 60);

    int bin;
    std::cin >> bin;

    Snake::UI::Terminate();

//
//    int dir;
//
//    while ((dir = getchar()) != 'q') {
//        getchar();
//        switch(dir) {
//            case 'a':
//                myGame.ChangeSnakeDirection(Snake::Model::Direction::LEFT);
//                break;
//            case 'd':
//                myGame.ChangeSnakeDirection(Snake::Model::Direction::RIGHT);
//                break;
//            case 's':
//                myGame.ChangeSnakeDirection(Snake::Model::Direction::DOWN);
//                break;
//            case 'w':
//                myGame.ChangeSnakeDirection(Snake::Model::Direction::UP);
//                break;
//        }
//        myGame.GameLoop();
//    }

    return 0;
}
