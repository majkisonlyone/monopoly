#include "Game.hpp"

Game::Game(int numberOfPlayers)
{
    players.reserve(numberOfPlayers);
    for( int playerIndex = 0; playerIndex < numberOfPlayers; playerIndex++)
    {
        players.emplace_back(Player());
    }

    gameboard = Board();

    for( int diceIndex = 0; diceIndex < 2; diceIndex++)
    {
        dice.emplace_back(Dice());
    }
}

void Game::takeTurn(Player& player)
{
    int pointsSum = 0;
    for(const auto& die : dice)
    {
        pointsSum += die.roll(); 
    }

    int boardSize = gameboard.fields.size();
    player.move(pointsSum, boardSize);

}

void Game::start(int maxNumberOfRounds)
{
    for(int round = 0; round > maxNumberOfRounds; round++)
    {
        for(auto& player : players)
        {
            takeTurn(player);
        }
    }
}