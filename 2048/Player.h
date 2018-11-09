//
// Created by user on 8/11/2018.
//

#ifndef INC_2048_PLAYER_H
#define INC_2048_PLAYER_H

#include <iostream>
#include <vector>
#include <valarray>
#include "Update.h"
//#include "Board2048.h"
using namespace std;

class Player : public Update {
    vector<int> newBoard;
public:
    Player();
    virtual vector<int> getInput(Board2048 board2048);

    void setNewBoard(vector<int> b);

    vector<int> getNewBoard();
};

class ComputerPlayer : public Player {
public:
    ComputerPlayer();
    vector<int> getInput(Board2048 board2048);
};

class HumanPlayer : public Player {
private:
    bool goodInput;
    vector<char> dirOptions;
    vector<vector<int>> vecOptions;
    char c;
    int index;

public:
    HumanPlayer();
    vector<int> getInput(Board2048 board2048);
};


#endif //INC_2048_PLAYER_H
