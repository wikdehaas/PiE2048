//
// Created by user on 8/11/2018.
//

#ifndef INC_2048_PLAYER_H
#define INC_2048_PLAYER_H

#include <iostream>
#include <vector>
#include <valarray>

using namespace std;

class Player {
    vector<int> newBoard;
public:
    virtual vector<int> getInput();

    void setNewBoard(vector<int> b) {
        newBoard = b;
    }

    vector<int> getNewBoard() {
        return newBoard;
    }
};

class ComputerPlayer : public Player {
private:
    vector<int> getInput() {

        return getNewBoard();
    }
};

class HumanPlayer : public Player, Update {
private:
    vector<int> getInput() {
        bool goodInput = false;
        vector<char> dirOptions = getDirections();
        vector<vector<int>> vecOptions = getVectors();


        char c;
        cout << "Input your wanted directions! (w,a,s,d)" << endl;
        while (!goodInput) {
            cin >> c;
            if (c != 'w' && c != 'a' && c != 's' && c != 'd') {
                cout << "This is not a correct input!" << endl;
            } else if (find(dirOptions.begin(), dirOptions.end(), c) != dirOptions.end()){
                int index = distance(dirOptions.begin(), find(dirOptions.begin(), dirOptions.end(), c));
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
