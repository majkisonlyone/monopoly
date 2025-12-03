#include "Game.hpp"
#include <algorithm>
#include <iostream>

Game::Game(int numberOfPlayers)
{
    players.reserve(numberOfPlayers);
    for (int playerIndex = 0; playerIndex < numberOfPlayers; playerIndex++)
    {
        players.emplace_back(Player(playerIndex));
    }

    gameboard = Board();

    for (int diceIndex = 0; diceIndex < 2; diceIndex++)
    {
        dice.emplace_back(Dice());
    }
}

void Game::takeTurn(Player &player)
{
    std::cout << "---------------\n";
    std::cout << "Player no.: " << player.getPlayerIndex() << "\n";
    std::cout << "---------------\n";
    int pointsSum = 0;
    for (const auto &die : dice)
    {
        pointsSum += die.roll();
    }
    std::cout <<"Total rolled: " << pointsSum <<"\n";

    int boardSize = gameboard.fields.size();
    player.move(pointsSum, boardSize);

    std::cout << "---------------\n";
}

void Game::start(int maxNumberOfRounds)
{
    for (int round = 0; round < maxNumberOfRounds; round++)
    {
        std::cout << "Current round: " << round << "\n";
        std::cout <<"=================\n";
        for (auto &player : players)
        {
            takeTurn(player);
            if(isWinnerDetermined())
            {
                std::cout << "Winner determined!\n";
                return;
            }
        }
        std::cout <<"=================\n";
    }
}

bool Game::isWinnerDetermined()
{
    int numberOfNonBankruptPlayers =
        std::count_if(players.begin(), players.end(), [](const auto &player)
                      { return not player.isBankrupt(); });

    return numberOfNonBankruptPlayers == 1;
}