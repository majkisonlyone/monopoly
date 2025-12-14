#pragma once

class Player
{
  public:
    Player(int playerIndex);
   
    int getMoney();
    void addMoney(int amount);
    void subtractMoney(int amount);
    bool isBankrupt() const;
    int getPlayerIndex();

  private:
    int money = 200;
    int playerIndex;
};