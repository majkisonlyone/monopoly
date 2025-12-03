#include "Game.hpp"
#include <iostream>

int main()
{
    int numberOfPlayers = 2;
    std::cout << "Creating game for number of players: " << numberOfPlayers << "\n";
    Game monopolyGame = Game(numberOfPlayers);

    int maxNumberOfRounds = 10;
    std::cout << "Starting game with max number of rounds: " << maxNumberOfRounds << "\n";
    monopolyGame.start(maxNumberOfRounds);

    return 0;
}