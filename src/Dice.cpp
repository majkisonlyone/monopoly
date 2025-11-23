#include "Dice.hpp"
#include <random>

int Dice::roll()
{
    std::random_device rd;  
    std::mt19937 gen(rd());         // Mersenne Twister engine
    std::uniform_int_distribution<> dist(1, 6);

    return dist(gen);
}