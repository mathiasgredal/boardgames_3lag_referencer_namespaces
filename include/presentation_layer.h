#ifndef PRESENTATION_LAYER_H
#define PRESENTATION_LAYER_H

#include "data_layer.h"
#include "logic_layer.h"
#include <string>
#include <vector>

namespace presentation {
void display_best(std::string input);
void display_all(const std::vector<data::BoardGame>& input);
void compare_avg_geek(const std::vector<data::BoardGame>& input);

void display_statistics(std::vector<data::BoardGame> input, float data::BoardGame::*type);
}

#endif // PRESENTATION_LAYER_H
