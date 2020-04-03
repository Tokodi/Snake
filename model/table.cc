#include "table.h"

#include <chrono>
#include <exception>
#include <iostream>
#include <random>

using std::exception;
using std::make_unique;
using std::mt19937;
using std::uniform_int_distribution;
using std::unique_ptr;
using std::vector;

namespace Snake {
namespace Model {

Table::Table(unsigned int height, unsigned int width)
    : _height(height), _width(width) {
    Initialize();
}

unsigned int Table::GetHeight() const {
    return _height;
}

unsigned int Table::GetWidth() const {
    return _width;
}

//TODO: handle exception when called
void Table::SetField(unsigned int x, unsigned int y, FieldType fieldType) {
    _table->at(y)->at(x) = fieldType;
}

//TODO: handle exception when called
FieldType Table::GetField(unsigned int x, unsigned int y) const {
    return _table->at(y)->at(x);
}

void Table::DebugPrint() const {
    for (auto const& row : *_table) {
        for (auto const& field : *row) {
            switch(field) {
                case FieldType::EMPTY:
                    std::cout << "0";
                    break;
                case FieldType::SNAKE:
                    std::cout << "S";
                    break;
                case FieldType::FOOD:
                    std::cout << "F";
                    break;
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}

void Table::GenerateFood() {
    unsigned int x = GetRandomNumber(0, _width - 1);
    unsigned int y = GetRandomNumber(0, _height - 1);

    SetField(x, y, FieldType::FOOD);
}

void Table::Initialize() {
    _table = make_unique<vector<unique_ptr<vector<FieldType>>>>(_height);
    for (auto& row : *_table) {
        row = make_unique<vector<FieldType>>(_width, FieldType::EMPTY);
    }
}

//TODO: Why can't I use using system_clock::now ... ?
int Table::GetRandomNumber(int min, int max) {
   static thread_local mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());
   uniform_int_distribution<int> distribution(min, max);
   return distribution(generator);
}

} // ns Model
} // ns Snake
