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
    vector<int> newBoard;
public:
    virtual vector<int> getInput(Board2048){};

    void setNewBoard(vector<int> b) {
        newBoard = b;
    }

    vector<int> getNewBoard() {
        return newBoard;
    }
};

class ComputerPlayer : public Player {
public:
    vector<int> getInput(Board2048 bo) {
        cout<<2131324<<endl;
        return getNewBoard();
    }
};

class HumanPlayer : public Player {
private:
    bool goodInput;
    vector<char> dirOptions;
    vector<vector<int>> vecOptions;
    char c;
    int index;

public:
    vector<int> getInput(Board2048 bo) {
        goodInput = false;
        cout << 1 << endl;
        vecOptions.clear();
        cout << 4 << endl;
        vecOptions = getVectors(bo);
        cout << 5 << endl;
        dirOptions.clear();
        cout << 2 << endl;
        dirOptions = getDirections();
        cout << 3 << endl;
        cout << "Input your wanted directions! (w,a,s,d)" << endl;
        while (!goodInput) {
            cin >> c;
            if (c != 'w' && c != 'a' && c != 's' && c != 'd') {
                cout << "This is not a correct input!" << endl;
            } else if (find(dirOptions.begin(), dirOptions.end(), c) != dirOptions.end()){
                index = distance(dirOptions.begin(), find(dirOptions.begin(), dirOptions.end(), c));
                setNewBoard(vecOptions[index]);
                goodInput = true;
            } else {
                cout << "This direction does not move any number" << endl;
                goodInput = true;
            }
        }
        return getNewBoard();
    }
};


#endif //INC_2048_PLAYER_H
