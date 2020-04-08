#include "game.h"

#include <chrono>
#include <exception>
#include <iostream>
#include <random>

using std::cerr;
using std::exception;
using std::make_shared;
using std::make_unique;
using std::mt19937;
using std::shared_ptr;
using std::uniform_int_distribution;

using Position = std::pair<int, int>;

namespace Snake {
namespace Model {

Game::Game() {
}

void Game::NewGame(unsigned int tableWidth, unsigned int tableHeight) {
    _isGameOver = false;
    _isRoundOver = true;
    _lifeCounter = START_LIFE_COUNT;
    _score = 0;

    CreateGameTable(tableWidth, tableHeight);
}

void Game::NewRound() {
    if (_isGameOver)
        return;

    _isRoundOver = false;
    ClearTable();
    CreateSnake();
    PlaceSnakeOnTable();
    CreateFood();
    PlaceFoodOnTable();
}

void Game::StepGame() {
    if (_isRoundOver)
        return;

    if (_snake->GetLength() == _table->GetWidth() * _table->GetHeight()) {
        _isRoundOver = true;
        return;
    }

    if (!_food) {
        CreateFood();
        PlaceFoodOnTable();
    }

    _snake->Move();

    if (!_snake->IsAlive() || !_table->IsInside(_snake->GetHeadPosition())) {
        _isRoundOver = true;
        return;
    }

    if (_snake->GetHeadPosition() == _food->GetPosition()) {
        ++_score;
        _snake->Grow();
        _food.release();
    }

    UpdateSnakeOnTable();
}

unsigned int Game::GetLifeCounter() const {
    return _lifeCounter;
}

unsigned int Game::GetScore() const {
    return _score;
}

bool Game::IsGameOver() const {
    return _isGameOver;
}

bool Game::IsRoundOver() const {
    return _isRoundOver;
}

const shared_ptr<const Table> Game::GetTable() const {
    return _table;
}

unsigned int Game::GetTableWidth() const {
    return _table->GetWidth();
}

unsigned int Game::GetTableHeight() const {
    return _table->GetHeight();
}

FieldType Game::GetTableField(std::pair<int, int> position) const {
    return _table->GetField(position);
}

void Game::ChangeSnakeDirection(Direction newDirection) const {
    if (!_snake->IsAlive())
        return;

    _snake->ChangeDirection(newDirection);
}

void Game::SetSnakeDirection(Direction direction) const {
    _snake->SetCurrentDirection(direction);
}

void Game::CreateGameTable(unsigned int width, unsigned int height) {
    _table.reset();
    _table = make_shared<Table>(width, height);
}

void Game::ClearTable() {
    _table->Clear();
}

void Game::CreateSnake() {
    _snake.reset();
    _snake = make_unique<Snake>(GetRandomPosition());
}

void Game::PlaceSnakeOnTable() {
    try {
        _table->SetField(_snake->GetHeadPosition(), FieldType::SNAKE);
        _table->SetField(_snake->GetTailPosition(), FieldType::SNAKE);
    } catch (exception& e) {
        cerr << "[" << __func__ << "] Exception caught: " << e.what() << std::endl;
    }
}

void Game::UpdateSnakeOnTable() {
    try {
        _table->SetField(_snake->GetTrailPosition(), FieldType::EMPTY);
        _table->SetField(_snake->GetTailPosition(), FieldType::SNAKE);
        _table->SetField(_snake->GetHeadPosition(), FieldType::SNAKE);
    } catch (exception& e) {
        cerr << "[" << __func__ << "] Exception caught: " << e.what() << std::endl;
    }
}

void Game::CreateFood() {
    Position randomFoodPosition;
    do {
        randomFoodPosition = GetRandomPosition();
    } while (_table->GetField(randomFoodPosition) != FieldType::EMPTY);
    _food = make_unique<Food>(randomFoodPosition);
}

void Game::PlaceFoodOnTable() {
    try {
        _table->SetField(_food->GetPosition(), FieldType::FOOD);
    } catch (exception& e) {
        cerr << "[" << __func__ << "] Exception caught: " << e.what() << std::endl;
    }
}

Position Game::GetRandomPosition() const {
    unsigned int posX = GetRandomNumber(0, _table->GetWidth() - 1);
    unsigned int posY = GetRandomNumber(0, _table->GetHeight() - 1);

    return Position(posX, posY);
}

int Game::GetRandomNumber(int min, int max) const {
   static thread_local mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());
   uniform_int_distribution<int> distribution(min, max);
   return distribution(generator);
}

} // ns Model
} // ns Snake
