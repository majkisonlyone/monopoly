#pragma once
#include "Player.hpp"

class IField
{
  public:
    virtual void onStepAction(Player &) = 0;
    virtual ~IField() = default;
};
