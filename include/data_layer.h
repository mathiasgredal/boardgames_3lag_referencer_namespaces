#ifndef DATA_LAYER_H
#define DATA_LAYER_H

#include <sstream>
#include <string>
#include <vector>

namespace data {
class BoardGame {
public:
    int rank;
    std::string title;
    float avgRating;
    float geekRating;
    float numVoters;
};

std::vector<BoardGame> get_games_from_file();

}

#endif // DATA_LAYER_H
