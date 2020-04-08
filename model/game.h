#pragma once

#include "food.h"
#include "snake.h"
#include "table.h"

namespace Snake {
namespace Model {

class Game {
public:
    Game();

    //Game
    void NewGame(unsigned int tableWidth, unsigned int tableHeight);
    void NewRound();
    void StepGame();

    unsigned int GetLifeCounter() const;
    unsigned int GetScore() const;

    bool IsGameOver() const;
    bool IsRoundOver() const;

    //Table
    const std::shared_ptr<const Table> GetTable() const;
    unsigned int GetTableWidth() const;
    unsigned int GetTableHeight() const;
    FieldType GetTableField(std::pair<int, int> position) const;

    //Snake
    void ChangeSnakeDirection(Direction newDirection) const;
    void SetSnakeDirection(Direction direction) const;

    static constexpr unsigned int START_LIFE_COUNT = 5;

private:
    //Table
    void CreateGameTable(unsigned int width, unsigned int height);
    void ClearTable();

    //Snake
    void CreateSnake();
    void PlaceSnakeOnTable();
    void UpdateSnakeOnTable();

    //Food
    void CreateFood();
    void PlaceFoodOnTable();

    //Misc
    std::pair<int, int> GetRandomPosition() const;
    int GetRandomNumber(int min, int max) const;

private:
    bool _isRoundOver;
    bool _isGameOver;
    unsigned int _lifeCounter;
    unsigned int _score;

    std::unique_ptr<Snake> _snake;
    std::shared_ptr<Table> _table;
    std::unique_ptr<Food> _food;
};

} // ns Model
} // ns Snake
