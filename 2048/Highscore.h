//
// Created by user on 22/11/2018.
//

#ifndef INC_2048_HIGHSCORE_H
#define INC_2048_HIGHSCORE_H

#include <vector>
#include <string>

using namespace std;

/* The class Highscore contains the variables and functions needed to add scores to a highscore list, retrieve scores
 * from the same highscore list, and print them to the screen in descending order.
 *
 * Functions used in other classes/files:
 * Game2048: Highscore, addHighscore, viewHighscore
 */

class Highscore {
private:
    //private variables
    struct highscore {
        string hsName;
        int hsValue;

        bool operator<(const highscore& a) const
        {
            return hsValue < a.hsValue;
        }
    };

    int maxNameLength;
    vector<highscore> hsList;
    //private functions
    vector<highscore> readHighscoreList();
    void setMaxNameLength(int length);
    void setHSList();

public:
    //public functions
    explicit Highscore(int length); //Constructor
    void addHighscore(string name, int score);
    void viewHighscore();
};

#endif //INC_2048_HIGHSCORE_H
