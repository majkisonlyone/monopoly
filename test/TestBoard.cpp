#include "Board.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace ::testing;

TEST(BoardTest, WhenCreatingBoard_ShouldPopulateFields)
{
    Board sut{};

    EXPECT_THAT(sut.fields, Not(IsEmpty()));
}