#include "Board.hpp"
#include <memory>

Board::Board()
{
    fields.push_back(std::make_unique<FieldStart>());
    fields.push_back(std::make_unique<FieldEmpty>());
    fields.push_back(std::make_unique<FieldEmpty>());
    fields.push_back(std::make_unique<FieldReward>());
    fields.push_back(std::make_unique<FieldPenalty>());
    fields.push_back(std::make_unique<FieldEmpty>());
    fields.push_back(std::make_unique<FieldEmpty>());
    fields.push_back(std::make_unique<FieldEmpty>());
    fields.push_back(std::make_unique<FieldPenalty>());
    fields.push_back(std::make_unique<FieldPenalty>());
    fields.push_back(std::make_unique<FieldReward>());
    fields.push_back(std::make_unique<FieldReward>());
    fields.push_back(std::make_unique<FieldEmpty>());
    fields.push_back(std::make_unique<FieldEmpty>());
    fields.push_back(std::make_unique<FieldEmpty>());
    fields.push_back(std::make_unique<FieldEmpty>());
    fields.push_back(std::make_unique<FieldEmpty>());
    fields.push_back(std::make_unique<FieldReward>());
    fields.push_back(std::make_unique<FieldPenalty>());
    fields.push_back(std::make_unique<FieldEmpty>());
    fields.push_back(std::make_unique<FieldEmpty>());
    fields.push_back(std::make_unique<FieldEmpty>());
    fields.push_back(std::make_unique<FieldPenalty>());
    fields.push_back(std::make_unique<FieldPenalty>());
    fields.push_back(std::make_unique<FieldReward>());
    fields.push_back(std::make_unique<FieldReward>());
    fields.push_back(std::make_unique<FieldEmpty>());
    fields.push_back(std::make_unique<FieldEmpty>());
    fields.push_back(std::make_unique<FieldEmpty>());
    fields.push_back(std::make_unique<FieldEmpty>());
    fields.push_back(std::make_unique<FieldEmpty>());
    fields.push_back(std::make_unique<FieldReward>());
    fields.push_back(std::make_unique<FieldPenalty>());
    fields.push_back(std::make_unique<FieldEmpty>());
    fields.push_back(std::make_unique<FieldEmpty>());
    fields.push_back(std::make_unique<FieldEmpty>());
    fields.push_back(std::make_unique<FieldPenalty>());
    fields.push_back(std::make_unique<FieldPenalty>());
    fields.push_back(std::make_unique<FieldReward>());
    fields.push_back(std::make_unique<FieldReward>());
}

void Board::movePlayer(Player& player, int pointsSum)
{
    const auto& playerIndex = player.getPlayerIndex();

    std::cout << "Previous position: " << playersOnFields.at(playerIndex) << "\n";
    playersOnFields.at(playerIndex) = (playersOnFields.at(playerIndex) + pointsSum) % fields.size();
    std::cout << "New position: " << playersOnFields.at(playerIndex) << "\n";

    fields.at(playersOnFields.at(playerIndex))->onStepAction(player);
}