#include "game.h"

#include <cstdio>

int main() {
    Snake::Model::Game myGame;
    myGame.Initialize(10, 10);

    int dir;

    while ((dir = getchar()) != 'q') {
        getchar();
        switch(dir) {
            case 'a':
                myGame.ChangeSnakeDirection(Snake::Model::Direction::LEFT);
                break;
            case 'd':
                myGame.ChangeSnakeDirection(Snake::Model::Direction::RIGHT);
                break;
            case 's':
                myGame.ChangeSnakeDirection(Snake::Model::Direction::DOWN);
                break;
            case 'w':
                myGame.ChangeSnakeDirection(Snake::Model::Direction::UP);
                break;
        }
        myGame.GameLoop();
    }

    return 0;
}
