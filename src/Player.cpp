#include "Player.hpp"
#include <iostream>

Player::Player(int playerIndex) : playerIndex{playerIndex} {}

int Player::getPlayerIndex() { return playerIndex; }

void Player::move(int pointsSum, int boardSize)
{
    std::cout << "Previous possition: " << fieldIndex << "\n";
    fieldIndex = (fieldIndex + pointsSum) % boardSize;
    std::cout << "New possition: " << fieldIndex << "\n";
}

int Player::getMoney() { return money; }

void Player::addMoney(int amount) { money += amount; }

void Player::subtractMoney(int amount) { money -= amount; }

bool Player::isBankrupt() const { return money <= 0; }