#include "table.h"

#include <exception>
#include <iostream>

using std::exception;
using std::make_unique;
using std::unique_ptr;
using std::vector;

using Position = std::pair<int, int>;

namespace Snake {
namespace Model {

Table::Table(const unsigned int width,
             const unsigned int height)
    : _width(width),
      _height(height) {
    Initialize();
}

void Table::Clear() {
    for (auto& row : *_table) {
        for (auto& field : *row) {
            field = FieldType::EMPTY;
        }
    }
}

unsigned int Table::GetWidth() const {
    return _width;
}

unsigned int Table::GetHeight() const {
    return _height;
}

//Note: Might throw exception
void Table::SetField(Position position, FieldType fieldType) {
    _table->at(position.second)->at(position.first) = fieldType;
}

//Note: Might throw exception
FieldType Table::GetField(Position position) const {
    return _table->at(position.second)->at(position.first);
}

//TODO: Magic
bool Table::IsInside(Position position) const {
    if (static_cast<unsigned>(position.first) < _width) {
        if (static_cast<unsigned>(position.second) < _height) {
            return true;
        }
    }
    return false;
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
    std::cout << std::endl;
}

void Table::Initialize() {
    _table = make_unique<vector<unique_ptr<vector<FieldType>>>>(_height);
    for (auto& row : *_table) {
        row = make_unique<vector<FieldType>>(_width, FieldType::EMPTY);
    }
}

} // ns Model
} // ns Snake
