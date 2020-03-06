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

float minVal(std::vector<data::BoardGame>& games, float data::BoardGame::*sortParam);
float maxVal(std::vector<data::BoardGame>& games, float data::BoardGame::*sortParam);
float medianVal(std::vector<data::BoardGame>& games, float data::BoardGame::*sortParam);
float avgVal(const std::vector<data::BoardGame>& games, float data::BoardGame::*sortParam);

void selectionSort(std::vector<data::BoardGame>& games, float data::BoardGame::*sortParam);
void bubbleSort(std::vector<data::BoardGame>& games, float data::BoardGame::*sortParam);
void mergeSort(std::vector<data::BoardGame>& games, int left, int right, float data::BoardGame::*sortParam);

}

#endif // LOGIC_LAYER_H
