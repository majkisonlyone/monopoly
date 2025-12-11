#include "Fields/FieldEmpty.hpp"
#include "Fields/FieldPenalty.hpp"
#include "Fields/FieldReward.hpp"
#include "Fields/FieldStart.hpp"
#include <gtest/gtest.h>

namespace
{
constexpr int dummyPlayerIndex{1};
}

struct FieldTest : public testing::Test
{
    Player testPlayer{dummyPlayerIndex};
};

TEST_F(FieldTest, givenPenaltyField_whenOnStepAction_shouldSubtractPlayersMoney)
{
    const int testPlayerMoneyBeforeOnStepAction = 200;
    const int testPlayerMoneyAfterOnStepAction = 100;

    EXPECT_EQ(testPlayer.getMoney(), testPlayerMoneyBeforeOnStepAction);

    FieldPenalty testPenaltyField{};
    testPenaltyField.onStepAction(testPlayer);

    EXPECT_EQ(testPlayer.getMoney(), testPlayerMoneyAfterOnStepAction);
}

TEST_F(FieldTest, givenRewardField_whenOnStepAction_shouldAddPlayersMoney)
{
    const int testPlayerMoneyBeforeOnStepAction = 200;
    const int testPlayerMoneyAfterOnStepAction = 300;

    EXPECT_EQ(testPlayer.getMoney(), testPlayerMoneyBeforeOnStepAction);

    FieldReward testRewardField{};
    testRewardField.onStepAction(testPlayer);

    EXPECT_EQ(testPlayer.getMoney(), testPlayerMoneyAfterOnStepAction);
}

TEST_F(FieldTest, givenStartField_whenOnStepAction_shouldAddPlayersMoney)
{
    const int testPlayerMoneyBeforeOnStepAction = 200;
    const int testPlayerMoneyAfterOnStepAction = 400;

    EXPECT_EQ(testPlayer.getMoney(), testPlayerMoneyBeforeOnStepAction);

    FieldStart testStartField{};
    testStartField.onStepAction(testPlayer);

    EXPECT_EQ(testPlayer.getMoney(), testPlayerMoneyAfterOnStepAction);
}

TEST_F(FieldTest, givenStartField_whenOnPassAction_shouldAddPlayersMoney)
{
    const int testPlayerMoneyBeforeOnStepAction = 200;
    const int testPlayerMoneyAfterOnStepAction = 400;

    EXPECT_EQ(testPlayer.getMoney(), testPlayerMoneyBeforeOnStepAction);

    FieldStart testStartField{};
    testStartField.onPassAction(testPlayer);

    EXPECT_EQ(testPlayer.getMoney(), testPlayerMoneyAfterOnStepAction);
}