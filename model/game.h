#pragma once

#include "food.h"
#include "snake.h"
#include "table.h"

namespace Snake {
namespace Model {

class Game {
public:
    Game();

    void Initialize(unsigned int tableWidth, unsigned int tableHeight);
    void StepGame();
    void ChangeSnakeDirection(Direction newDirection) const;

    //TODO: Unit Test
    unsigned int GetTableWidth();
    unsigned int GetTableHeight();

    FieldType GetTableField(std::pair<int, int> position);

    bool IsGameOver() const;
    unsigned int GetScore() const;

private:
    void CreateGameTable(unsigned int width, unsigned int height);
    void CreateSnake();
    void PlaceSnakeOnTable();
    void UpdateSnakeOnTable();
    void CreateFood();
    void AddFoodToTable();

    const std::pair<int, int> GetRandomPosition() const;
    unsigned int GetRandomNumber(unsigned int min, unsigned int max) const;

    bool _isInitialized;
    bool _isGameOver;
    unsigned int _score;

    std::unique_ptr<Snake> _snake;
    std::unique_ptr<Table> _table;
    std::unique_ptr<Food> _food;

    static constexpr int SNAKE_START_POS_X = 0;
    static constexpr int SNAKE_START_POS_Y = 0;
};

} // ns Model
} // ns Snake
