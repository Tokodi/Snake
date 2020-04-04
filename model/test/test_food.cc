#include "food.h"

#include <gtest/gtest.h>

using std::make_unique;
using std::unique_ptr;

using Position = std::pair<int, int>;

namespace Snake {
namespace Model {

static constexpr int TEST_FOOD_POSITION_X = 42;
static constexpr int TEST_FOOD_POSITION_Y = 42;

class FoodTestFixture : public ::testing::Test {
protected:
    void SetUp() override {
        testFood = make_unique<Food>(TEST_FOOD_POSITION_X, TEST_FOOD_POSITION_Y);
    }

    void TearDown() override {
    }

    unique_ptr<Food> testFood;
};

TEST_F(FoodTestFixture, testFoodAccessors) {
    EXPECT_EQ(testFood->GetPosition(), Position(42, 42));
}

} // ns Model
} // ns Snake
