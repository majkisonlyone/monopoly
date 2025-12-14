#include "Player.hpp"

Player::Player(int playerIndex) : playerIndex{playerIndex} {}

int Player::getPlayerIndex() { return playerIndex; }

int Player::getMoney() { return money; }

void Player::addMoney(int amount) { money += amount; }

void Player::subtractMoney(int amount) { money -= amount; }

bool Player::isBankrupt() const { return money <= 0; }