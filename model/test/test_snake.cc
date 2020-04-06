#include "snake.h"

#include <gtest/gtest.h>

using std::make_unique;
using std::unique_ptr;

using Position = std::pair<int, int>;

namespace Snake {
namespace Model {

static constexpr int TEST_SNAKE_START_POSITION_X = 0;
static constexpr int TEST_SNAKE_START_POSITION_Y = 0;

class SnakeTestFixture : public ::testing::Test {
protected:
    void SetUp() override {
        testSnake = make_unique<Snake>(Position(TEST_SNAKE_START_POSITION_X, TEST_SNAKE_START_POSITION_Y));
    }

    void TearDown() override {
    }

    unique_ptr<Snake> testSnake;
};

TEST_F(SnakeTestFixture, testSnakeGetters) {
    ASSERT_EQ(testSnake->GetHeadPosition(), Position(0, 0));
    ASSERT_EQ(testSnake->GetTailPosition(), Position(0, 0));
    ASSERT_EQ(testSnake->GetTrailPosition(), Position(0, 0));
}

TEST_F(SnakeTestFixture, testSnakeInitialization) {
    EXPECT_EQ(testSnake->IsAlive(), true);
}

TEST_F(SnakeTestFixture, testSnakeMovement) {
    testSnake->Move();

    ASSERT_EQ(testSnake->GetHeadPosition(), Position(1, 0));
    ASSERT_EQ(testSnake->GetTailPosition(), Position(1, 0));
    ASSERT_EQ(testSnake->GetTrailPosition(), Position(0, 0));

    testSnake->ChangeDirection(Direction::DOWN);
    testSnake->Move();

    ASSERT_EQ(testSnake->GetHeadPosition(), Position(1, 1));
    ASSERT_EQ(testSnake->GetTailPosition(), Position(1, 1));
    ASSERT_EQ(testSnake->GetTrailPosition(), Position(1, 0));

    testSnake->ChangeDirection(Direction::LEFT);
    testSnake->Move();

    ASSERT_EQ(testSnake->GetHeadPosition(), Position(0, 1));
    ASSERT_EQ(testSnake->GetTailPosition(), Position(0, 1));
    ASSERT_EQ(testSnake->GetTrailPosition(), Position(1, 1));

    testSnake->ChangeDirection(Direction::UP);
    testSnake->Move();

    ASSERT_EQ(testSnake->GetHeadPosition(), Position(0, 0));
    ASSERT_EQ(testSnake->GetTailPosition(), Position(0, 0));
    ASSERT_EQ(testSnake->GetTrailPosition(), Position(0, 1));

    //Shoudl not change direction
    testSnake->ChangeDirection(Direction::DOWN);
    testSnake->Move();

    ASSERT_EQ(testSnake->GetHeadPosition(), Position(0, -1));
    ASSERT_EQ(testSnake->GetTailPosition(), Position(0, -1));
    ASSERT_EQ(testSnake->GetTrailPosition(), Position(0, 0));
}

TEST_F(SnakeTestFixture, testSnakeGrownment) {
    testSnake->Grow();
    testSnake->Move();

    ASSERT_EQ(testSnake->GetHeadPosition(), Position(1, 0));
    ASSERT_EQ(testSnake->GetTailPosition(), Position(0, 0));
    ASSERT_EQ(testSnake->GetTrailPosition(), Position(0, 0));
}

} // ns Model
} // ns Snake
