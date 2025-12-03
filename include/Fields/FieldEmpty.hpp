#include "IField.hpp"

class FieldEmpty : public IField
{
  public:
    void onStepAction(Player &player) override {}
};