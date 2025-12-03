#include <memory>
#include <vector>

#include "Fields/FieldEmpty.hpp"
#include "Fields/FieldPenalty.hpp"
#include "Fields/FieldReward.hpp"
#include "Fields/FieldStart.hpp"

class Board
{
  public:
    Board();

    std::vector<std::unique_ptr<IField>> fields;
};