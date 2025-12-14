#include "IField.hpp"
#include <iostream>

class FieldStart : public IField
{
  public:
    void onStepAction(Player& player) override
    {
        player.addMoney(200);
        std::cout << "Stepped on START. Player money added: 200.\n";
    }
    void onPassAction(Player& player) override
    {
        player.addMoney(200);
        std::cout << "Passed START. Player money added: 200.\n";
    }
};