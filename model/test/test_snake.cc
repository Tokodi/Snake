#include "snake.h"

#include <gtest/gtest.h>

using std::make_unique;
using std::unique_ptr;

namespace Snake {
namespace Model {

static constexpr unsigned int TEST_SNAKE_START_POSITION_X = 0;
static constexpr unsigned int TEST_SNAKE_START_POSITION_Y = 0;

class SnakeTestFixture : public ::testing::Test {
protected:
    void SetUp() override {
        testSnake = make_unique<Snake>(TEST_SNAKE_START_POSITION_X, TEST_SNAKE_START_POSITION_Y);
    }

    void TearDown() override {
    }

    unique_ptr<Snake> testSnake;
};

TEST_F(SnakeTestFixture, testSnakeInitialization) {
    EXPECT_EQ(testSnake->IsAlive(), true);
    EXPECT_EQ(testSnake->GetHeadPosition().first, 1);
    EXPECT_EQ(testSnake->GetHeadPosition().second, 0);
    EXPECT_EQ(testSnake->GetTailPosition().first, 0);
    EXPECT_EQ(testSnake->GetTailPosition().second, 0);
}

TEST_F(SnakeTestFixture, testSnakeMovement) {
    testSnake->Move();

    EXPECT_EQ(testSnake->GetHeadPosition().first, 2);
    EXPECT_EQ(testSnake->GetHeadPosition().second, 0);
    EXPECT_EQ(testSnake->GetTailPosition().first, 1);
    EXPECT_EQ(testSnake->GetTailPosition().second, 0);

    testSnake->ChangeDirection(Direction::DOWN);
    testSnake->Move();

    EXPECT_EQ(testSnake->GetHeadPosition().first, 2);
    EXPECT_EQ(testSnake->GetHeadPosition().second, 1);
    EXPECT_EQ(testSnake->GetTailPosition().first, 2);
    EXPECT_EQ(testSnake->GetTailPosition().second, 0);

    testSnake->ChangeDirection(Direction::LEFT);
    testSnake->Move();

    EXPECT_EQ(testSnake->GetHeadPosition().first, 1);
    EXPECT_EQ(testSnake->GetHeadPosition().second, 1);
    EXPECT_EQ(testSnake->GetTailPosition().first, 2);
    EXPECT_EQ(testSnake->GetTailPosition().second, 1);

    testSnake->ChangeDirection(Direction::UP);
    testSnake->Move();

    EXPECT_EQ(testSnake->GetHeadPosition().first, 1);
    EXPECT_EQ(testSnake->GetHeadPosition().second, 0);
    EXPECT_EQ(testSnake->GetTailPosition().first, 1);
    EXPECT_EQ(testSnake->GetTailPosition().second, 1);

    //Shoudl not change direction
    testSnake->ChangeDirection(Direction::DOWN);
    testSnake->Move();

    EXPECT_EQ(testSnake->GetHeadPosition().first, 1);
    EXPECT_EQ(testSnake->GetHeadPosition().second, -1);
    EXPECT_EQ(testSnake->GetTailPosition().first, 1);
    EXPECT_EQ(testSnake->GetTailPosition().second, 0);
}

TEST_F(SnakeTestFixture, testSnakeGrownment) {
    testSnake->Grow();
    testSnake->Move();

    EXPECT_EQ(testSnake->GetHeadPosition().first, 2);
    EXPECT_EQ(testSnake->GetHeadPosition().second, 0);
    EXPECT_EQ(testSnake->GetTailPosition().first, 0);
    EXPECT_EQ(testSnake->GetTailPosition().second, 0);
}

} // ns Model
} // ns Snake
