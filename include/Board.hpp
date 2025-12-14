#include <memory>
#include <vector>
#include <map>
#include <iostream>

#include "Fields/FieldEmpty.hpp"
#include "Fields/FieldPenalty.hpp"
#include "Fields/FieldReward.hpp"
#include "Fields/FieldStart.hpp"

using PlayerIndex = int;
using FieldIndex = int;
class Board
{
  public:
    Board();

    std::vector<std::unique_ptr<IField>> fields;

    std::map<PlayerIndex, FieldIndex> playersOnFields;

    void movePlayer(Player& player,int pointsSum);
};