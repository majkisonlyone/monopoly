#include "IField.hpp"

class FieldPenalty : public IField
{
  public:
    void onStepAction(Player &player) { player.subtractMoney(100); }
};