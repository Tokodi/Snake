#include "game.h"

#include <chrono>
#include <random>

using std::make_unique;
using std::mt19937;
using std::uniform_int_distribution;

using Position = std::pair<int, int>;

namespace Snake {
namespace Model {

//TODO: Handle exceptions

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
    if (_isGameOver || !_isInitialized)
        return;

    if (!_food) {
        CreateFood();
        AddFoodToTable();
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
    _table->DebugPrint();
}

void Game::ChangeSnakeDirection(Direction newDirection) const {
    if (!_snake->IsAlive())
        return;

    _snake->ChangeDirection(newDirection);
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
    _snake = make_unique<Snake>(SNAKE_START_POS_X, SNAKE_START_POS_Y);
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

void Game::AddFoodToTable() {
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
