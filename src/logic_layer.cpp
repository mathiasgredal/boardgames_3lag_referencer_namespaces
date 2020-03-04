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

void sortList(std::vector<data::BoardGame>& games, SortType type)
{
    switch (type) {
    case logic::Avg:
        std::sort(games.begin(), games.end(), [](const data::BoardGame& lhs, const data::BoardGame& rhs) {
            return lhs.avgRating < rhs.avgRating;
        });
        break;
    case logic::Geek:
        std::sort(games.begin(), games.end(), [](const data::BoardGame& lhs, const data::BoardGame& rhs) {
            return lhs.geekRating < rhs.geekRating;
        });
        break;
    case logic::Bayesian:
        std::sort(games.begin(), games.end(), [](const data::BoardGame& lhs, const data::BoardGame& rhs) {
            return bayesianAvg(lhs.numVoters, lhs.avgRating) < bayesianAvg(rhs.numVoters, rhs.avgRating);
        });
        break;
    }
}

float minRating(std::vector<data::BoardGame> games, SortType type)
{
    sortList(games, type);

    switch (type) {
    case logic::Avg:
        return games.front().avgRating;
    case logic::Geek:
        return games.front().geekRating;
    case logic::Bayesian:
        return bayesianAvg(games.front().numVoters, games.front().avgRating);
    }
}

float maxRating(std::vector<data::BoardGame> games, SortType type)
{
    sortList(games, type);

    switch (type) {
    case logic::Avg:
        return games.back().avgRating;
    case logic::Geek:
        return games.back().geekRating;
    case logic::Bayesian:
        return bayesianAvg(games.back().numVoters, games.back().avgRating);
    }
}

float medianRating(std::vector<data::BoardGame> games, SortType type)
{
    sortList(games, type);

    if (games.size() % 2) {
        // Even number, we should average the 2 middle numbers

    } else {
        // Odd number, we should just return the middle number
    }

    switch (type) {
    case logic::Avg:
        return games.back().avgRating;
    case logic::Geek:
        return games.back().geekRating;
    case logic::Bayesian:
        return bayesianAvg(games.back().numVoters, games.back().avgRating);
    }
}

float avgRating(const std::vector<data::BoardGame>& games, SortType type)
{
}

}
