#include "logic_layer.h"

namespace logic {

std::vector<data::BoardGame> reverseNew(const std::vector<data::BoardGame>& games)
{
    std::vector<data::BoardGame> gamesCopy = {};

    for (int i = games.size() - 1; i >= 0; i--) {
        gamesCopy.push_back(games[i]);
    }
}

void reverseSame(std::vector<data::BoardGame>& games)
{
    for (size_t i = 0; i < games.size() / 2; i++) {
        // Get the corrosponding element from the back side
        data::BoardGame back = games[games.size() - i - 1];

        // Swap
        games[games.size() - i - 1] = games[i];
        games[i] = back;
    }
}

float bayesianAvg(int numVoters, float avgRating, float C, float m)
{
    return (C * m + avgRating * numVoters) / (C + numVoters);
}

void sortList(std::vector<data::BoardGame>& games, float data::BoardGame::*sortParam)
{
    std::sort(games.begin(), games.end(), [&sortParam](const data::BoardGame& lhs, const data::BoardGame& rhs) {
        return lhs.*sortParam < rhs.*sortParam;
    });
}

float minVal(std::vector<data::BoardGame>& games, float data::BoardGame::*sortParam)
{
    sortList(games, sortParam);

    return games.front().*sortParam;
}

float maxVal(std::vector<data::BoardGame>& games, float data::BoardGame::*sortParam)
{
    sortList(games, sortParam);

    return games.back().*sortParam;
}

float medianVal(std::vector<data::BoardGame>& games, float data::BoardGame::*sortParam)
{
    sortList(games, sortParam);

    if (games.size() % 2)
        // Even number, we should average the 2 middle numbers
        return (games.at(games.size() / 2).*sortParam + games.at(games.size() / 2 - 1).*sortParam) / 2;

    else
        // Odd number, we should just return the middle number
        return games.at(games.size() / 2).*sortParam;
}

float avgVal(const std::vector<data::BoardGame>& games, float data::BoardGame::*sortParam)
{
    float sum = 0;

    for (const auto& game : games) {
        sum += game.*sortParam;
    }

    return sum / games.size();
}

}
