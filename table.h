#ifndef table_h
#define table_h

#include "record.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>

class table {

private:

    std::map<std::string, record>nbaTable;

public:

    void add_score(const std::string& name, double score);      //adds a new score for the named player.

    int num_players()const;     //returns the total number of players for whom a score has been recorded.

    //vector<string> best_recent()const;

    double average_best()const;     //returns the average of the best scores of all players. You may assume that at least one player has been added.
    
    std::string best_overall()const;        //returns the name of the player with the highest overall average. You may assume that at least one player has been added.
    
    int novice_count()const;        //returns the number of novice players. Your implementation should use a library algorithm.

};
#endif