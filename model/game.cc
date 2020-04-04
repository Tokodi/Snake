#include "game.h"

#include <chrono>
#include <iostream>
#include <random>

using std::make_unique;
using std::mt19937;
using std::uniform_int_distribution;

namespace Snake {
namespace Model {

Game::Game()
    : _isInitialized(false),
      _isGameOver(false),
      _score(0) {
}

void Game::Initialize(unsigned int tableWidth, unsigned int tableHeight) {
    if (_isInitialized)
        return;

    CreateGameTable(tableWidth, tableHeight);
    CreateSnake();
    PlaceSnakeOnTable();

    _isInitialized = true;
}

void Game::GameLoop() {
    if (!_food) {
        CreateFood();
        AddFoodToTable();
    }

    //TODO: Remove
    _table->DebugPrint();

    _snake->Move();

    if (_snake->IsAlive() || !_table->IsInside(_snake->GetHeadPosition())) {
        _isGameOver = true;
        return;
    }

    if (_snake->GetHeadPosition() == _food->GetPosition()) {
        ++_score;
        _snake->Grow();
        _food.release();
    }

    UpdateSnakeOnTable();
}

bool Game::IsGameOver() const {
    return _isGameOver;
}

unsigned int Game::GetScore() const {
    return _score;
}

void Game::CreateGameTable(unsigned int width, unsigned int height) {
    _table = make_unique<Table>(width, height);
}

void Game::CreateSnake() {
    //TODO: use SNAKE_START_POS_X, SNAKE_START_POS_Y
    _snake = make_unique<Snake>(0, 0);
}

//TODO: Handle exception
void Game::PlaceSnakeOnTable() {
    //TODO: This only works with the fixed 2 start length
    //Guess snakes born that way...
    _table->SetField(_snake->GetHeadPosition(), FieldType::SNAKE);
    _table->SetField(_snake->GetTailPosition(), FieldType::SNAKE);
}

void Game::UpdateSnakeOnTable() {
    std::cout << "OOPS" << std::endl;
    _table->SetField(_snake->GetTrailPosition(), FieldType::EMPTY);
    _table->SetField(_snake->GetHeadPosition(), FieldType::SNAKE);
}

void Game::CreateFood() {
    unsigned int posX = GetRandomNumber(0, _table->GetWidth() - 1);
    unsigned int posY = GetRandomNumber(0, _table->GetHeight() - 1);
    _food = make_unique<Food>(posX, posY);
}

void Game::AddFoodToTable() {
    _table->SetField(_food->GetPosition(), FieldType::FOOD);
}

//TODO: Why can't I use using system_clock::now ... ?
unsigned int Game::GetRandomNumber(unsigned int min, unsigned int max) const {
   static thread_local mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());
   uniform_int_distribution<int> distribution(min, max);
   return distribution(generator);
}

} // ns Model
} // ns Snake
