#include "table.h"

#include <exception>
#include <iostream>

using std::exception;
using std::make_unique;
using std::unique_ptr;
using std::vector;

namespace Snake {
namespace Model {

Table::Table(unsigned int height, unsigned int width)
    : _height(height),
      _width(width) {
    Initialize();
}

unsigned int Table::GetHeight() const {
    return _height;
}

unsigned int Table::GetWidth() const {
    return _width;
}

bool Table::IsInside(const Position& position) const {
    //TODO: Solve this mistery
    std::cout << position.first << " " << position.second << " " << _width << " " << _height << std::endl;
    if (position.first < 0) {
        return false;
    }

    if (position.second < 0) {
        return false;
    }

    if (position.first >= _width) {
        return false;
    }

    if (position.second >= _height) {
        return false;
    }

    return true;

    //if ((0 <= position.first < _width) && (0 <= position.second < _height))
    //    return true;

    //std::cout << "WFT" << std::endl;
    //return false;
}

//TODO: handle exception when called
void Table::SetField(Position position, FieldType fieldType) {
    _table->at(position.second)->at(position.first) = fieldType;
}

//TODO: handle exception when called
FieldType Table::GetField(Position position) const {
    return _table->at(position.second)->at(position.first);
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

void Table::Initialize() {
    _table = make_unique<vector<unique_ptr<vector<FieldType>>>>(_height);
    for (auto& row : *_table) {
        row = make_unique<vector<FieldType>>(_width, FieldType::EMPTY);
    }
}

} // ns Model
} // ns Snake
