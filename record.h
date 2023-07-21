#ifndef record_h
#define record_h

#include <iostream>
#include <vector>

class record {

private:

    double best_score_stored;
    std::vector<double> records;

public:

    record();       //empty record

    record(double score);       //empty record with one score

    void add_score(double score);       //record a new score for the player. Scores are guaranteed to be non-negative

    double best_score()const;       //returns the best score ever added to the record (or 0 if none)

    double overall_average()const;      //returns the average of all scores added to the record(or 0 if none)

    double recent_average()const;      //returns the average of the last 10 scores added to the record (or 0 if none). If there are fewer than 10 scores in a record, it returns the average of those scores.
                                       
    bool novice()const;     //return whether fewer than 10 scores have been recorded.

};

#endif
