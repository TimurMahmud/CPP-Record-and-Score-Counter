#include <iostream>
#include "record.h"
#include "table.h"

using namespace std;
int main() {
    record score;    
    score.add_score(10);
    score.add_score(10);
    score.add_score(10);
    score.add_score(10);
    score.add_score(10);
    score.add_score(10);
    score.add_score(10);
    score.add_score(10);
    score.add_score(10);
    score.add_score(10);
    score.add_score(100);

    cout << "best score:" << score.best_score() << endl;
    cout << "recent average:" << score.recent_average() << endl;
    cout << "overall average:" << score.overall_average() << endl;
    cout << "is novice?:" << score.novice() << endl;

    table player;
    player.add_score("Westbrook", 22);
    player.add_score("Westbrook", 29);
    player.add_score("Westbrook", 22);
    player.add_score("Westbrook", 49);
    player.add_score("Westbrook", 22);
    player.add_score("Westbrook", 22);
    player.add_score("Westbrook", 26);
    player.add_score("Westbrook", 22);
    player.add_score("Westbrook", 27);
    player.add_score("Westbrook", 22);
    player.add_score("Westbrook", 22);
    player.add_score("James", 27);
    player.add_score("Davis", 35);
    
    cout << "number of players:" << player.num_players() << endl;   
    cout << "best average:" << player.average_best() << endl;
    cout << "best overall:" << player.best_overall() << endl;
    cout << "number of novices:" << player.novice_count() << endl;

    
    return 0;
}
