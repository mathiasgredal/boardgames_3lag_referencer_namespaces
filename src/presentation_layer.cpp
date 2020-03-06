#include "presentation_layer.h"
#include <iostream>

namespace presentation {

void display_best(std::string game)
{
    std::cout << "Best game according to BGG: " << game;
}

void display_all(const std::vector<data::BoardGame>& input)
{
    for (const data::BoardGame& boardgame : input) {
        std::cout << boardgame.rank << ": " << boardgame.title << " " << boardgame.avgRating << " " << boardgame.geekRating << " " << boardgame.numVoters << std::endl;
    }
}

void compare_avg_geek(const std::vector<data::BoardGame>& input)
{
    for (size_t i = 0; i < input.size(); i++) {
        std::cout << input.at(i).rank << ": " << input.at(i).title << " - Geek: " << input.at(i).avgRating << ", Bayesian: " << logic::bayesianAvg(input.at(i).numVoters, input.at(i).avgRating) << std::endl;
    }
}

void display_statistics(std::vector<data::BoardGame> input, float data::BoardGame::*type)
{
    std::cout << "Min: " << logic::minVal(input, type) << std::endl;
    std::cout << "Max: " << logic::maxVal(input, type) << std::endl;
    std::cout << "Median: " << logic::medianVal(input, type) << std::endl;
    std::cout << "Avg: " << logic::avgVal(input, type) << std::endl;
}

}
