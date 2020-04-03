#pragma once

#include <memory>
#include <vector>

namespace Snake {
namespace Model {

using Position = std::pair<int, int>;

enum class FieldType { EMPTY, SNAKE, FOOD };

class Table {
public:
    Table(unsigned int height, unsigned int width);

    unsigned int GetHeight() const;
    unsigned int GetWidth() const;

    bool IsInside(const Position& position) const;

    void SetField(Position position, FieldType fieldType);
    FieldType GetField(Position position) const;

    //TODO: remove
    void DebugPrint() const;

private:
    void Initialize();

    const unsigned int _height;
    const unsigned int _width;

    std::unique_ptr<std::vector<std::unique_ptr<std::vector<FieldType>>>> _table;
};

} // ns Model
} // ns Snake
