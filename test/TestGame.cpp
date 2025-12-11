#include "Game.hpp"
#include <gtest/gtest.h>
#include <vector>

namespace
{
constexpr int dummyNumOfPlayers{1};
constexpr int dummyPlayerIndex{0};
} // namespace

class GameTest : public testing::Test
{
  public:
    void setupDefaultPlayers()
    {
        sut.players = {Player(dummyPlayerIndex), Player(dummyPlayerIndex),
                       Player(dummyPlayerIndex), Player(dummyPlayerIndex),
                       Player(dummyPlayerIndex)};
    }

    void bankruptAllButOnePlayer()
    {
        std::for_each(sut.players.begin(), sut.players.end() - 1,
                      [](auto& player) { player.subtractMoney(200); });
    }

    void bankruptAllButLastTwoPlayers()
    {
        std::for_each(sut.players.begin(), sut.players.end() - 2,
                      [](auto& player) { player.subtractMoney(200); });
    }

    Game sut{dummyNumOfPlayers};
};

TEST_F(GameTest, givenNoBankrupts_shouldNotDetermineWinner)
{
    setupDefaultPlayers();
    EXPECT_FALSE(sut.isWinnerDetermined());
}

TEST_F(GameTest, givenAllButOneBankrupts_shouldDetermineWinner)
{
    setupDefaultPlayers();
    bankruptAllButOnePlayer();
    EXPECT_TRUE(sut.isWinnerDetermined());
}

TEST_F(GameTest, givenAllLastTwoPlayers_shouldNotDetermineWinner)
{
    setupDefaultPlayers();
    bankruptAllButLastTwoPlayers();
    EXPECT_FALSE(sut.isWinnerDetermined());
}