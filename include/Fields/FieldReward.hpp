#include "IField.hpp"

class FieldReward : public IField
{
  public:
    void onStepAction(Player &player) { player.addMoney(100); }
};