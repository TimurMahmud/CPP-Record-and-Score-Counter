#include "table.h"
#include "record.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

    void table::add_score(const string& name, double score) {       //adds a new score for the named player.
        if (nbaTable.find(name) != nbaTable.end()) {        //if the score is not at the end of the vector then add new score into the map given the name
            nbaTable[name].add_score(score);
        }
        else {
            record newRecord(score);        //if the name does not exist then create a new record and add score to that record
            nbaTable[name] = newRecord;
        }
    }    
    int table::novice_count()const {        //returns the number of novice players. Your implementation should use a library algorithm.
        int novicePlayers = 0;      //novices playres is set to 0
        for (auto i = nbaTable.begin(); i != nbaTable.end(); ++i) {     //iterates through elements in map 
            if (i->second.novice() == 1) {      //if a player has less than 10 scores than increment novice players by 1
                novicePlayers += 1;
            }
        }
        return novicePlayers;       //return number of novice players
    }
    
    double table::average_best()const {     //returns the average of the best scores of all players. You may assume that at least one player has been added.
        double total = 0;       //total is set to 0
        for (auto i = nbaTable.begin(); i != nbaTable.end(); ++i) {     //iterates through all scores in the map and finds best score for each player
            total += i->second.best_score();        //adds best scores to the total
        }
        double average = total / nbaTable.size();       //calculates mean by dividing by the total elements added
        return average;     //returns mean
    }
    
    int table::num_players()const {     //returns the total number of players for whom a score has been recorded.         
        return nbaTable.size();     //returns number of elements in each player record
    }

    string table::best_overall()const {     //returns the name of the player with the highest overall average. You may assume that at least one player has been added.
        string name;    //name is initialised
        double bestAverage = 0;        //best average is initialised to 0
              
        for (auto i = nbaTable.begin(); i != nbaTable.end(); ++i) {     //iterates through elements in map 
            double overallAverage = i->second.overall_average();       
            if (overallAverage > bestAverage) {        //if overall average is greater than best average then best average is updated
                bestAverage = overallAverage;
                name = i->first;        //name of player with best average is stored in name
            }
        }
        return name;        //name of player is returned
    }

    /*vector<string> table::best_recent() {
        vector<string> names;
        double temp = 0;
    }*/

    

    

    