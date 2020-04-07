#include "game.h"

#include <chrono>
#include <random>

using std::shared_ptr;
using std::make_unique;
using std::make_shared;
using std::mt19937;
using std::uniform_int_distribution;

using Position = std::pair<int, int>;

namespace Snake {
namespace Model {

//TODO: Handle exceptions

Game::Game() {
}

void Game::NewGame(unsigned int tableWidth, unsigned int tableHeight) {
    CreateGameTable(tableWidth, tableHeight);
    CreateSnake();
    PlaceSnakeOnTable();
    CreateFood();
    PlaceFoodOnTable();

    _isGameOver = false;
    _score = 0;
}

void Game::StepGame() {
    if (_isGameOver)
        return;

    if (!_food) {
        CreateFood();
        PlaceFoodOnTable();
    }

    _snake->Move();

    if (!_snake->IsAlive() || !_table->IsInside(_snake->GetHeadPosition())) {
        _isGameOver = true;
        return;
    }

    if (_snake->GetHeadPosition() == _food->GetPosition()) {
        ++_score;
        _snake->Grow();
        _food.release();
    }

    UpdateSnakeOnTable();

    //TODO: Remove
    //_table->DebugPrint();
}

void Game::ChangeSnakeDirection(Direction newDirection) const {
    if (!_snake->IsAlive())
        return;

    _snake->ChangeDirection(newDirection);
}

const shared_ptr<const Table> Game::GetTable() const {
    return _table;
}

unsigned int Game::GetTableWidth() {
    return _table->GetWidth();
}

unsigned int Game::GetTableHeight() {
    return _table->GetHeight();
}

FieldType Game::GetTableField(std::pair<int, int> position) {
    return _table->GetField(position);
}

bool Game::IsGameOver() const {
    return _isGameOver;
}

unsigned int Game::GetScore() const {
    return _score;
}

void Game::CreateGameTable(unsigned int width, unsigned int height) {
    _table.reset();
    _table = make_shared<Table>(width, height);
}

void Game::CreateSnake() {
    _snake.reset();
    _snake = make_unique<Snake>(GetRandomPosition());
}

void Game::PlaceSnakeOnTable() {
    _table->SetField(_snake->GetHeadPosition(), FieldType::SNAKE);
    _table->SetField(_snake->GetTailPosition(), FieldType::SNAKE);
}

void Game::UpdateSnakeOnTable() {
    _table->SetField(_snake->GetTrailPosition(), FieldType::EMPTY);
    _table->SetField(_snake->GetTailPosition(), FieldType::SNAKE);
    _table->SetField(_snake->GetHeadPosition(), FieldType::SNAKE);
}

void Game::CreateFood() {
    Position randomFoodPosition;
    do {
        randomFoodPosition = GetRandomPosition();
    } while (_table->GetField(randomFoodPosition) != FieldType::EMPTY);
    _food = make_unique<Food>(randomFoodPosition);
}

void Game::PlaceFoodOnTable() {
    _table->SetField(_food->GetPosition(), FieldType::FOOD);
}

const Position Game::GetRandomPosition() const {
    unsigned int posX = GetRandomNumber(0, _table->GetWidth() - 1);
    unsigned int posY = GetRandomNumber(0, _table->GetHeight() - 1);

    return Position(posX, posY);
}

unsigned int Game::GetRandomNumber(unsigned int min, unsigned int max) const {
   static thread_local mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());
   uniform_int_distribution<int> distribution(min, max);
   return distribution(generator);
}

} // ns Model
} // ns Snake
