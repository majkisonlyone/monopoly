#include "Board.hpp"

Board::Board()
{

    fields = {FieldStart(),   FieldEmpty(),   FieldEmpty(),   FieldReward(),
              FieldPenalty(), FieldEmpty(),   FieldEmpty(),   FieldEmpty(),
              FieldPenalty(), FieldPenalty(), FieldReward(),  FieldReward(),
              FieldEmpty(),   FieldEmpty(),   FieldEmpty(),   FieldEmpty(),
              FieldEmpty(),   FieldReward(),  FieldPenalty(), FieldEmpty(),
              FieldEmpty(),   FieldEmpty(),   FieldPenalty(), FieldPenalty(),
              FieldReward(),  FieldReward(),  FieldEmpty(),   FieldEmpty(),
              FieldEmpty(),   FieldEmpty(),   FieldEmpty(),   FieldReward(),
              FieldPenalty(), FieldEmpty(),   FieldEmpty(),   FieldEmpty(),
              FieldPenalty(), FieldPenalty(), FieldReward(),  FieldReward()};
}