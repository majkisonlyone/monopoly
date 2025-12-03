#include "Player.hpp"
#include <iostream>

Player::Player(int playerIndex) : playerIndex{playerIndex} {}

int Player::getPlayerIndex() { return playerIndex; }

int Player::getFieldIndex() {return fieldIndex; }

void Player::move(int pointsSum, int boardSize)
{
    std::cout << "Previous position: " << fieldIndex << "\n";
    fieldIndex = (fieldIndex + pointsSum) % boardSize;
    std::cout << "New position: " << fieldIndex << "\n";
}

int Player::getMoney() { return money; }

void Player::addMoney(int amount) { money += amount; }

void Player::subtractMoney(int amount) { money -= amount; }

bool Player::isBankrupt() const { return money <= 0; }