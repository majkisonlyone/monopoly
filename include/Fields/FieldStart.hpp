#include "IField.hpp"

class FieldStart : public IField
{
  public:
    void onStepAction(Player& player) override { player.addMoney(200); }
    void onPassAction(Player& player) override { player.addMoney(200); }
};