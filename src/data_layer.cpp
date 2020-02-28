#include "data_layer.h"
#include <algorithm>
#include <fstream> // filestream

namespace data {

std::vector<BoardGame> get_games_from_file()
{
    using namespace std;
    vector<BoardGame> boardGames;
    string line, word;
    int current = -1;
    int next = 0;

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
        current = 0;
        next = line.find(';');

        BoardGame boardGame = BoardGame();

        for (int i = 0; next > 0; i++) {
            // Get the next word and update indices to next word
            word = line.substr(current, next - current);
            current = next + 1;
            next = line.find(';', current);

            // Push current word to corresponding vector
            switch (i) {
            case 0:
                boardGame.rank = stoi(word);
                //ranking.push_back(s); // stoi is String TO Int
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
                boardGame.numVoters = stoi(word);
                break;
            }
        }

        boardGames.push_back(boardGame);
    }

    return boardGames;
}

}
