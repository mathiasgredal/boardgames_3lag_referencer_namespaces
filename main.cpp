#include "data_layer.h"
#include "presentation_layer.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> games;

    try {
        games = data::get_games_from_file();
        presentation::display_best(games[0]);
    } catch (exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
