//
// Created by user on 8/11/2018.
//

#ifndef INC_2048_GAME2048_H
#define INC_2048_GAME2048_H

#include <string>
#include "Board2048.h"
//#include "HumanPlayer.h"
//#include "ComputerPlayer.h"
#include "Player.h"
//#include "Update.h"

using namespace std;

class Game2048 {
    unsigned const int SIZE = 4;
//    bool gameOver = false;
    string inputPlayerType;
//    vector<char> posDir;

    Player* choosePlayerType() {
        cout << 3 << endl;
        Player* player;
        cout << 4 << endl;
        ComputerPlayer CP;
        cout << 5 << endl;
        HumanPlayer HP;
        cout << 6 << endl;
        cout << "What is the player type? Computer or human?" << endl;
        cin >> inputPlayerType;
        if (inputPlayerType == "computer" || inputPlayerType == "Computer") {
            player = &CP;
            cout << "Computer chosen." << endl;
        }
        else {  if(inputPlayerType == "human" || inputPlayerType == "Human"){
                player = &HP;
                cout << "Human player chosen." << endl;
            }
            else {
                player = &HP;
                cout << "Unknown input given. Human player assumed" << endl;
            }
        }
    return player;
    }

//    bool checkGameOver() {
//        cout << 1;
//        posDir = getDirections();
//        cout << 2;
//        if (posDir.empty()) {
//            return true;
//        }
//        return false;
//    }

public:
    void runGame() {
        cout << 1 << endl;
        HumanPlayer HP;
        Player* player = &HP;
        cout << player << endl;
        cout << 2 << endl;
        Board2048 board;


        board.setBoardSize(SIZE);
        board.createBoard();
        board.addRandomTile();
        board.addRandomTile();
        board.visualizeBoard(board.getBoard());
//        while (!checkGameOver()) {
        for (int i = 0; i < 20; i++) {
            cout << i << endl;
            vector<int> vejdedh = player->getInput(board);
            for (auto i: vejdedh)
                cout<< i<< endl;
            board.setBoard(vejdedh);
            board.addRandomTile();
            board.visualizeBoard(board.getBoard());
        }
//        }
        cout << "Game over!" << endl;
    }


};


#endif //INC_2048_GAME2048_H
