#include "presentation_layer.h"
#include <iostream>

namespace presentation {

void display_best(std::string game)
{
    std::cout << "Best game according to BGG: " << game;
}

void display_all(const std::vector<data::BoardGame>& input)
{
    for (auto& boardgame : input) {
        std::cout << boardgame.avgRating << std::endl;
    }
    //    std::for_each(input.begin(), input.end(), [](const std::string& item) {
    //        std::cout << item << std::endl;
    //    });
}

}
