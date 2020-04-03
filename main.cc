#include "table.h"

int main() {
    Snake::Model::Table myTable(10,20);
    myTable.SetField(3, 3, Snake::Model::FieldType::FOOD);
    myTable.DebugPrint();

    return 0;
}
