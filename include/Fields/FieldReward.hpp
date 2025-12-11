#include "IField.hpp"

class FieldReward : public IField
{
  public:
    void onStepAction(Player& player) override { player.addMoney(100); }
    void onPassAction(Player&) override {}
};