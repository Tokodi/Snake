#pragma once

#include <memory>
#include <vector>

namespace Snake {
namespace Model {

enum class FieldType { EMPTY, SNAKE, FOOD };

class Table {
public:
    Table(unsigned int width, unsigned int height);

    unsigned int GetWidth() const;
    unsigned int GetHeight() const;

    void SetField(std::pair<int, int> position, FieldType fieldType);
    FieldType GetField(std::pair<int, int> position) const;

    bool IsInside(const std::pair<int, int>& position) const;

    void DebugPrint() const;

private:
    void Initialize();

    const unsigned int _width;
    const unsigned int _height;

    std::unique_ptr<std::vector<std::unique_ptr<std::vector<FieldType>>>> _table;
};

} // ns Model
} // ns Snake
