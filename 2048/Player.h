//
// Created by user on 8/11/2018.
//

#ifndef INC_2048_PLAYER_H
#define INC_2048_PLAYER_H

#include <iostream>
#include <vector>
#include <valarray>
#include "Update.h"

using namespace std;

class Player : public Update {
    string name;
public:
    Player() = default;
    virtual vector<int> getInput(Board2048 &board2048);
    void setName(string &n);
    string getName();
};

class ComputerPlayer : public Player {
    int nextStep(vector<int> &nextBoard);
    int boardValueFun(vector<int> currBoard, int score);
public:
    ComputerPlayer() = default;
    vector<int> getInput(Board2048 &board2048) override;
};

class HumanPlayer : public Player {
public:
    HumanPlayer() = default;
    vector<int> getInput(Board2048 &board2048) override;
};


#endif //INC_2048_PLAYER_H
