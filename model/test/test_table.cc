#include "table.h"

#include <gtest/gtest.h>

using std::make_unique;
using std::unique_ptr;
using std::out_of_range;

namespace Snake {
namespace Model {

static constexpr unsigned int TEST_TABLE_HEIGHT = 10;
static constexpr unsigned int TEST_TABLE_WIDTH = 15;

class ModelTestFixture : public ::testing::Test {
protected:
    void SetUp() override {
        testTable = make_unique<Table>(TEST_TABLE_HEIGHT, TEST_TABLE_WIDTH);
    }

    void TearDown() override {
    }

    unique_ptr<Table> testTable;
};

TEST_F(ModelTestFixture, testTableSizeGetters) {
    EXPECT_EQ(10, testTable->GetHeight());
    EXPECT_EQ(15, testTable->GetWidth());
}

TEST_F(ModelTestFixture, testFieldAccessorsValid) {
    EXPECT_EQ(testTable->GetField(1, 5), FieldType::EMPTY);

    testTable->SetField(1, 5, FieldType::FOOD);

    EXPECT_EQ(testTable->GetField(1, 5), FieldType::FOOD);
}

TEST_F(ModelTestFixture, testFieldAccessorsException) {
    EXPECT_THROW(testTable->SetField(32, 0, FieldType::FOOD), out_of_range);
    EXPECT_THROW(testTable->GetField(32, 0), out_of_range);
}

TEST_F(ModelTestFixture, testFoodGenerator) {
    testTable->GenerateFood();

    int FoodCount = 0;
    for (int x = 0; x < TEST_TABLE_WIDTH; ++x) {
        for (int y = 0; y < TEST_TABLE_HEIGHT; ++y) {
            if (testTable->GetField(x, y) == FieldType::FOOD) {
                ++FoodCount;
            }
        }
    }

    EXPECT_EQ(1, FoodCount);
}

} // ns Model
} // ns Snake
