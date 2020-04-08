#include "game.h"

#include <gtest/gtest.h>

using std::make_unique;
using std::unique_ptr;

using Position = std::pair<int, int>;

namespace Snake {
namespace Model {

static constexpr unsigned int TEST_GAME_TABLE_WIDTH = 20;
static constexpr unsigned int TEST_GAME_TABLE_HEIGHT = 15;

//TODO: Unit test the game model
class GameTestFixture : public ::testing::Test {
protected:
    void SetUp() override {
        testGame = make_unique<Game>();
        testGame->NewGame(TEST_GAME_TABLE_WIDTH, TEST_GAME_TABLE_HEIGHT);
    }

    void TearDown() override {
    }

    unique_ptr<Game> testGame;
};

TEST_F(GameTestFixture, testGameInitialization) {
    EXPECT_EQ(testGame->IsGameOver(), false);
    EXPECT_EQ(testGame->IsRoundOver(), true);
    EXPECT_EQ(testGame->GetLifeCounter(), Game::START_LIFE_COUNT);
    EXPECT_EQ(testGame->GetScore(), 0);
    EXPECT_EQ(testGame->GetTableWidth(), TEST_GAME_TABLE_WIDTH);
    EXPECT_EQ(testGame->GetTableHeight(), TEST_GAME_TABLE_HEIGHT);
    //EXPECT_EQ(testGame->GetTableField(Position(0, 0)), FieldType::EMPTY);
}

TEST_F(GameTestFixture, testRoundInitialization) {
    testGame->NewRound();

    EXPECT_EQ(testGame->IsGameOver(), false);
    EXPECT_EQ(testGame->IsRoundOver(), false);
    //EXPECT_EQ(testGame->GetTableField(Position(0, 0)), FieldType::SNAKE);
}

TEST_F(GameTestFixture, testGameStep) {
    testGame->NewRound();
    testGame->StepGame();

    EXPECT_EQ(testGame->IsGameOver(), false);
    EXPECT_EQ(testGame->IsRoundOver(), false);
    //EXPECT_EQ(testGame->GetTableField(Position(0, 0)), FieldType::EMPTY);
    //EXPECT_EQ(testGame->GetTableField(Position(1, 0)), FieldType::SNAKE);
}

TEST_F(GameTestFixture, testChangeSnakeDirection) {
//    EXPECT_EQ(testGame->GetTableField(Position(0, 0)), FieldType::EMPTY);
//    testGame->NewRound();
//    EXPECT_EQ(testGame->GetTableField(Position(0, 0)), FieldType::SNAKE);
//    testGame->StepGame();
//    EXPECT_EQ(testGame->GetTableField(Position(1, 0)), FieldType::SNAKE);
//    testGame->ChangeSnakeDirection(Direction::DOWN);
//    testGame->StepGame();
//    EXPECT_EQ(testGame->GetTableField(Position(1, 1)), FieldType::SNAKE);
//    testGame->ChangeSnakeDirection(Direction::LEFT);
//    testGame->StepGame();
//    EXPECT_EQ(testGame->GetTableField(Position(0, 1)), FieldType::SNAKE);
//    testGame->ChangeSnakeDirection(Direction::UP);
//    testGame->StepGame();
//    EXPECT_EQ(testGame->GetTableField(Position(0, 0)), FieldType::SNAKE);
//    testGame->ChangeSnakeDirection(Direction::DOWN);
//    testGame->StepGame();
//    EXPECT_EQ(testGame->GetTableField(Position(0, 0)), FieldType::SNAKE);
//    EXPECT_EQ(testGame->IsRoundOver(), true);
}

} // ns Model
} // ns Snake
