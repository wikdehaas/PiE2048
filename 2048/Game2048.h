//
// Created by user on 8/11/2018.
//

#ifndef INC_2048_GAME2048_H
#define INC_2048_GAME2048_H

#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
//#include "Board2048.h"
//#include "HumanPlayer.h"
//#include "ComputerPlayer.h"

//#include "Update.h"


//class Board2048;
//class Player;
//class ComputerPlayer;
//class HumanPlayer;
using namespace std;

class Game2048 {
public:
    Game2048();
//    unsigned const int SIZE = 4;
//    bool gameOver = false;
    string inputPlayerType;
//    vector<char> posDir;

    Player* choosePlayerType();

//    bool checkGameOver() {
//        cout << 1;
//        posDir = getDirections();
//        cout << 2;
//        if (posDir.empty()) {
//            return true;
//        }
//        return false;
//    }


     void runGame();


};


#endif //INC_2048_GAME2048_H
