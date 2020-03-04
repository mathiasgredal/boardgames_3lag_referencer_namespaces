#ifndef LOGIC_LAYER_H
#define LOGIC_LAYER_H
#include "data_layer.h"
#include <vector>

namespace logic {
std::vector<data::BoardGame> reverseNew(const std::vector<data::BoardGame>& games);
void reverseSame(std::vector<data::BoardGame>& games);
///
/// \brief bayesianAvg
/// \param C is a good weight for this dataset
/// \param m is the average vote in the dataset
/// \return The bayesian average
///
float bayesianAvg(int numVoters, float avgRating, float C = 2000, float m = 5.5f);

enum SortType { Avg,
    Geek,
    Bayesian };

float minRating(const std::vector<data::BoardGame>& games, SortType type);
float maxRating(const std::vector<data::BoardGame>& games, SortType type);
float medianRating(const std::vector<data::BoardGame>& games, SortType type);
float avgRating(const std::vector<data::BoardGame>& games, SortType type);
}

#endif // LOGIC_LAYER_H
