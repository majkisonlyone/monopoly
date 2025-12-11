#include "IField.hpp"

class FieldPenalty : public IField
{
  public:
    void onStepAction(Player& player) override { player.subtractMoney(100); }
    void onPassAction(Player&) override {}
};