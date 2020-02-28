#ifndef PRESENTATION_LAYER_H
#define PRESENTATION_LAYER_H

#include "data_layer.h"
#include <string>
#include <vector>

namespace presentation {
void display_best(std::string input);
void display_all(const std::vector<data::BoardGame>& input);
}

#endif // PRESENTATION_LAYER_H
