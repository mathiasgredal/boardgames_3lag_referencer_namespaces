#include "data_layer.h"
#include <algorithm>
#include <fstream> // filestream

namespace data {

std::vector<BoardGame> get_games_from_file()
{
    using namespace std;
    vector<BoardGame> boardGames;
    string line, word;

    // Open file
    string filename = "data/top100bgg.csv";
    ifstream file(filename);

    if (!file) {
        throw runtime_error("Error - Couldn't open file: " + filename);
    }

    // Skip first line (titles). Then read every line after.
    getline(file, line);

    while (getline(file, line)) {
        // Initialize current index in string and find first delimiter ";"

        BoardGame boardGame = BoardGame();

        // stringstream class check1
        std::stringstream check1(line);

        int i = 0;
        // Loop through each value in line
        while (getline(check1, word, ';')) {
            // Push current word to corresponding vector
            switch (i) {
            case 0:
                boardGame.rank = stoi(word);
                break;
            case 1:
                boardGame.title = word;
                break;
            case 2:
                boardGame.avgRating = stof(word);
                break;
            case 3:
                boardGame.geekRating = stof(word);
                break;
            case 4:
                boardGame.numVoters = stof(word);
                break;
            }

            i++;
        }

        boardGames.push_back(boardGame);
    }

    return boardGames;
}

}
