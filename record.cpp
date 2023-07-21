#include "record.h"
#include <iostream>
#include <vector>

using namespace std;        

record::record() {      //empty record
    best_score_stored = 0;      //empty record set up with best score stored as 0 as no scores added
}

record::record(double score) {      //empty record with one score
    best_score_stored = score;      //the first score is given best score
    records.push_back(score);       //adds score to record
}

void record::add_score(double score) {      //record a new score for the player. Scores are guaranteed to be non-negative
    if (score > best_score_stored) {        //best score is changed if new score added is greater than current best score
        best_score_stored = score;      
    }
    records.push_back(score);       //adds score to record
}

double record::best_score()const {      //returns the best score ever added to the record (or 0 if none)
    if (best_score_stored == 0) {       //if there is no scores on record return 0
        return 0;
    }
    else {
        return best_score_stored;       //return best score if there are scores on record
    }
}

double record::overall_average()const {     //returns the average of all scores added to the record(or 0 if none)
    double total = 0;       //total set to 0
    for (auto i = std::begin(records); i != std::end(records); ++i) {       //iterates through all of the scores in the records
        total += *i;        //sum of all scores
    }
    double output = total / records.size();     //total score divided by the number of scores (mean)
    return output;      //returns mean
}

double record::recent_average()const {      //returns the average of the last 10 scores added to the record (or 0 if none). If there are fewer than 10 scores in a record, it returns the average of those scores.
    if (records.size() == 0) {      //if there are no scores then return 0
        return 0;
    }
    int it_cap = 10;        //maximum iterations set to 10
    if (records.size() < 10) {      //if records size is less than 10 st maximum iterations to record size
        it_cap = records.size();
    }
    double total = 0;       //total set to 0
    for (size_t i = 0; i < it_cap; ++i) {       //iterates through the most recent scores capped by it cap
        total += records[records.size() - 1 - i];   //sum of all scores which has been iterated through
    }
    double output = total / it_cap;     //total divided by amount of recent scores (mean)
    return output;      //returns mean
}

bool record::novice()const {        //return whether fewer than 10 scores have been recorded.
    if (records.size() < 10) {      //checks if less than 10 scores 
        return true;        //if there are less than 10 return true
    }
    return false;       //else return false
}
