//
// Created by user on 8/11/2018.
//

#include "Player.h"
#include <iostream>
#include <vector>
#include <valarray>
//#include "Update.h"
//#include "Board2048.h"

using namespace std;

//class Player : public Update {
//    vector<int> newBoard;
//public:
    Player::Player() {
        cout << "Player created" << endl;
    }

    vector<int> Player::getInput(Board2048){};

    void Player::setNewBoard(vector<int> b) {
        newBoard = b;
    }

    vector<int> Player::getNewBoard() {
        return newBoard;
    }
//};

//class ComputerPlayer : public Player {
    //public:
    ComputerPlayer::ComputerPlayer() {
        cout << "Computer player created" << endl;
    }

    vector<int> ComputerPlayer::getInput(Board2048 bo) {
        cout<<2131324<<endl;
        return getNewBoard();
    }
//};

//class HumanPlayer : public Player {
//private:
    HumanPlayer::HumanPlayer() {
        cout << "Human player created" << endl;
    }
//    bool goodInput;
//    vector<char> dirOptions;
//    vector<vector<int>> vecOptions;
//    char c;
//    int index;

//public:

    vector<int> HumanPlayer::getInput(Board2048 bo){
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
                Player::setNewBoard(vecOptions[index]);
                goodInput = true;
            } else {
                cout << "This direction does not move any number" << endl;
                goodInput = true;
            }
        }
        return getNewBoard();
    }
//};