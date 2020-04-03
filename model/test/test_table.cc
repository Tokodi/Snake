#include "table.h"

#include <gtest/gtest.h>

using std::make_unique;
using std::unique_ptr;
using std::out_of_range;

using Position = std::pair<int, int>;

namespace Snake {
namespace Model {

static constexpr unsigned int TEST_TABLE_HEIGHT = 10;
static constexpr unsigned int TEST_TABLE_WIDTH = 15;

class TableTestFixture : public ::testing::Test {
protected:
    void SetUp() override {
        testTable = make_unique<Table>(TEST_TABLE_HEIGHT, TEST_TABLE_WIDTH);
    }

    void TearDown() override {
    }

    unique_ptr<Table> testTable;
};

TEST_F(TableTestFixture, testTableSizeGetters) {
    EXPECT_EQ(10, testTable->GetHeight());
    EXPECT_EQ(15, testTable->GetWidth());
}

TEST_F(TableTestFixture, testFieldAccessorsValid) {
    EXPECT_EQ(testTable->GetField(Position(1, 5)), FieldType::EMPTY);

    testTable->SetField(Position(1, 5), FieldType::FOOD);

    EXPECT_EQ(testTable->GetField(Position(1, 5)), FieldType::FOOD);
}

TEST_F(TableTestFixture, testFieldAccessorsException) {
    EXPECT_THROW(testTable->SetField(Position(32, 0), FieldType::FOOD), out_of_range);
    EXPECT_THROW(testTable->GetField(Position(0, 32)), out_of_range);
}

} // ns Model
} // ns Snake
