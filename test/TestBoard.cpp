#include "Board.hpp"
#include "gmock/gmock.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace ::testing;

namespace
{
template <int Number> constexpr int incrementBy = Number;

template <int Number> constexpr int fieldIndex = Number;

constexpr int dummyPlayerIndex{1};
constexpr int startingFieldIndex{0};
} // namespace

class MockField : public IField
{
  public:
    // void onStepAction(Player& player) override {}
    // void onPassAction(Player&) override {}
    MOCK_METHOD(void, onStepAction, (Player&), (override));
    MOCK_METHOD(void, onPassAction, (Player&), (override));
};

struct BoardTestFixture : public testing::Test
{
    void setUpTestFields()
    {
        sut.fields.clear();

        fieldMocks.emplace_back(std::make_shared<NiceMock<MockField>>());
        fieldMocks.emplace_back(std::make_shared<NiceMock<MockField>>());
        fieldMocks.emplace_back(std::make_shared<NiceMock<MockField>>());
        fieldMocks.emplace_back(std::make_shared<NiceMock<MockField>>());
        fieldMocks.emplace_back(std::make_shared<NiceMock<MockField>>());

        sut.fields.push_back(fieldMocks.at(0));
        sut.fields.push_back(fieldMocks.at(1));
        sut.fields.push_back(fieldMocks.at(2));
        sut.fields.push_back(fieldMocks.at(3));
        sut.fields.push_back(fieldMocks.at(4));
    }

    void setUpTestPlayer()
    {
        sut.playersOnFields.insert({dummyPlayerIndex, startingFieldIndex});
    }

    Board sut{};
    std::vector<std::shared_ptr<NiceMock<MockField>>> fieldMocks{};
    Player testPlayer{dummyPlayerIndex};
};

TEST_F(BoardTestFixture, WhenPassingFields_ShouldTriggerOnPassAction)
{
    setUpTestFields();
    setUpTestPlayer();

    EXPECT_CALL(*fieldMocks.at(fieldIndex<1>), onPassAction(testPlayer));
    EXPECT_CALL(*fieldMocks.at(fieldIndex<2>), onPassAction(testPlayer));
    EXPECT_CALL(*fieldMocks.at(fieldIndex<3>), onStepAction(testPlayer));

    sut.movePlayer(testPlayer, incrementBy<3>);
}

TEST(BoardTest, WhenCreatingBoard_ShouldPopulateFields)
{
    Board sut{};

    EXPECT_THAT(sut.fields, Not(IsEmpty()));
}
