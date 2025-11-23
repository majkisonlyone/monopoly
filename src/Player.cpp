#include "Player.hpp"

void Player::move(int pointsSum, int boardSize)
{
    fieldIndex = (fieldIndex + pointsSum) % boardSize;

}