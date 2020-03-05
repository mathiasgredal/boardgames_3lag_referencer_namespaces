#include "data_layer.h"
#include "logic_layer.h"
#include "presentation_layer.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<data::BoardGame> games;

    try {
        games = data::get_games_from_file();
        //logic::reverseSame(games);

        presentation::display_all(games);
        presentation::display_statistics(games, &data::BoardGame::geekRating);
    } catch (exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
