//
// Created by user on 22/11/2018.
//

#ifndef INC_2048_HIGHSCORE_H
#define INC_2048_HIGHSCORE_H

#include <vector>
#include <string>

using namespace std;

class Highscore {
public:
    struct highscore {
        string hsName;
        int hsValue;

        bool operator<(const highscore& a) const
        {
            return hsValue < a.hsValue;
        }
    };
private:
    int maxNameLength;
    vector<highscore> hsList;
    void readHighscore();

public:
    explicit Highscore(int length);
    void addHighscore(string name, int score);
    void viewHighscore();
    void setMaxNameLength(int length);
    void setHSList(vector<highscore> &hsl);
};


#endif //INC_2048_HIGHSCORE_H
