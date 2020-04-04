#include "table.h"

#include <gtest/gtest.h>

using std::make_unique;
using std::out_of_range;
using std::unique_ptr;

using Position = std::pair<int, int>;

namespace Snake {
namespace Model {

static constexpr int TEST_TABLE_WIDTH = 15;
static constexpr int TEST_TABLE_HEIGHT = 10;

class TableTestFixture : public ::testing::Test {
protected:
    void SetUp() override {
        testTable = make_unique<Table>(TEST_TABLE_WIDTH, TEST_TABLE_HEIGHT);
    }

    void TearDown() override {
    }

    unique_ptr<Table> testTable;
};

TEST_F(TableTestFixture, testTableSizeGetters) {
    EXPECT_EQ(testTable->GetHeight(), 10);
    EXPECT_EQ(testTable->GetWidth(), 15);
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

TEST_F(TableTestFixture, testIsInside) {
    EXPECT_EQ(testTable->IsInside(Position(14, 9)), true);
    EXPECT_EQ(testTable->IsInside(Position(14, 10)), false);
    EXPECT_EQ(testTable->IsInside(Position(15, 9)), false);
    EXPECT_EQ(testTable->IsInside(Position(15, 10)), false);

    EXPECT_EQ(testTable->IsInside(Position(0, 0)), true);
    EXPECT_EQ(testTable->IsInside(Position(-1, 0)), false);
    EXPECT_EQ(testTable->IsInside(Position(0, -1)), false);
    EXPECT_EQ(testTable->IsInside(Position(-1, -1)), false);

    EXPECT_EQ(testTable->IsInside(Position(3, 9)), true);
}

} // ns Model
} // ns Snake
