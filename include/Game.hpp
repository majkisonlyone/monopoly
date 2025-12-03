#include "Board.hpp"
#include "Dice.hpp"
#include "Player.hpp"
#include <vector>

class Game
{
  public:
    Game(int numberOfPlayers);
    void start(int maxNumberOfRounds);
    void takeTurn(Player& player);
    bool isWinnerDetermined();

    std::vector<Player> players;
    Board gameboard;
    std::vector<Dice> dice;
};