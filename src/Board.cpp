#include "Board.hpp"
#include <memory>

Board::Board()
{
    fields.push_back(std::make_shared<FieldStart>());
    fields.push_back(std::make_shared<FieldEmpty>());
    fields.push_back(std::make_shared<FieldEmpty>());
    fields.push_back(std::make_shared<FieldReward>());
    fields.push_back(std::make_shared<FieldPenalty>());
    fields.push_back(std::make_shared<FieldEmpty>());
    fields.push_back(std::make_shared<FieldEmpty>());
    fields.push_back(std::make_shared<FieldEmpty>());
    fields.push_back(std::make_shared<FieldPenalty>());
    fields.push_back(std::make_shared<FieldPenalty>());
    fields.push_back(std::make_shared<FieldReward>());
    fields.push_back(std::make_shared<FieldReward>());
    fields.push_back(std::make_shared<FieldEmpty>());
    fields.push_back(std::make_shared<FieldEmpty>());
    fields.push_back(std::make_shared<FieldEmpty>());
    fields.push_back(std::make_shared<FieldEmpty>());
    fields.push_back(std::make_shared<FieldEmpty>());
    fields.push_back(std::make_shared<FieldReward>());
    fields.push_back(std::make_shared<FieldPenalty>());
    fields.push_back(std::make_shared<FieldEmpty>());
    fields.push_back(std::make_shared<FieldEmpty>());
    fields.push_back(std::make_shared<FieldEmpty>());
    fields.push_back(std::make_shared<FieldPenalty>());
    fields.push_back(std::make_shared<FieldPenalty>());
    fields.push_back(std::make_shared<FieldReward>());
    fields.push_back(std::make_shared<FieldReward>());
    fields.push_back(std::make_shared<FieldEmpty>());
    fields.push_back(std::make_shared<FieldEmpty>());
    fields.push_back(std::make_shared<FieldEmpty>());
    fields.push_back(std::make_shared<FieldEmpty>());
    fields.push_back(std::make_shared<FieldEmpty>());
    fields.push_back(std::make_shared<FieldReward>());
    fields.push_back(std::make_shared<FieldPenalty>());
    fields.push_back(std::make_shared<FieldEmpty>());
    fields.push_back(std::make_shared<FieldEmpty>());
    fields.push_back(std::make_shared<FieldEmpty>());
    fields.push_back(std::make_shared<FieldPenalty>());
    fields.push_back(std::make_shared<FieldPenalty>());
    fields.push_back(std::make_shared<FieldReward>());
    fields.push_back(std::make_shared<FieldReward>());
}

void Board::movePlayer(Player& player, int pointsSum)
{
    const auto& playerIndex = player.getPlayerIndex();

    std::cout << "Previous position: " << playersOnFields.at(playerIndex)
              << "\n";

    for (int i = 1; i < pointsSum; ++i)
    {
        const auto currentFieldIndex =
            (playersOnFields.at(playerIndex) + i) % fields.size();
        // std::cout << "currentFieldIndex= " << currentFieldIndex
        //           << " onPassAction\n";
        fields.at(currentFieldIndex)->onPassAction(player);
    }

    playersOnFields.at(playerIndex) =
        (playersOnFields.at(playerIndex) + pointsSum) % fields.size();

    std::cout << "New position: " << playersOnFields.at(playerIndex) << "\n";

    fields.at(playersOnFields.at(playerIndex))->onStepAction(player);
}