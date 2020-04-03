#pragma once

#include <memory>
#include <vector>

namespace Snake {
namespace Model {

enum class FieldType { EMPTY, SNAKE, FOOD };

class Table {
public:
    Table(unsigned int height, unsigned int width);

    unsigned int GetHeight() const;
    unsigned int GetWidth() const;

    void SetField(unsigned int x, unsigned int y, FieldType fieldType);
    FieldType GetField(unsigned int x, unsigned int y) const;

    void GenerateFood();

    //TODO: remove
    void DebugPrint() const;

private:
    void Initialize();
    int GetRandomNumber(int min, int max);

    const unsigned int _height;
    const unsigned int _width;

    std::unique_ptr<std::vector<std::unique_ptr<std::vector<FieldType>>>> _table;
};

} // ns Model
} // ns Snake
