
class Player
{
  public:
    Player(int playerIndex);
    void move(int pointsSum, int boardSize);
    int getMoney();
    void addMoney(int amount);
    void subtractMoney(int amount);
    bool isBankrupt() const;
    int getPlayerIndex();


  private:
    int money = 200;
    int fieldIndex = 0;
    int playerIndex;
};