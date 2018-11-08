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
#include "Update.h"

using namespace std;

class Game2048 : public Update{
    unsigned const int SIZE = 4;
    bool gameOver = false;
    string inputPlayerType;
    vector<char> posDir;

    Player choosePlayerType() {
        Player player;
        ComputerPlayer CP;
        HumanPlayer HP;
        cout << "What is the player type? Computer or human?" << endl;
        cin >> inputPlayerType;
        if (inputPlayerType == "computer" || inputPlayerType == "Computer") {
            Player* player = &CP;
            cout << "Computer chosen." << endl;
        }
        else {  if(inputPlayerType == "human" || inputPlayerType == "Human"){
                Player* player = &HP;
                cout << "Human player chosen." << endl;
            }
            else {
                Player* player = &HP;
                cout << "Unknown input given. Human player assumed" << endl;
            }
        }
    return player;
    }

    bool checkGameOver() {
        posDir = getDirections();
        if (posDir.empty()) {
            return true;
        }
        return false;
    }

public:
    void runGame() {
        Player player = choosePlayerType();
        Board2048 board;


        board.setSize(SIZE);
        board.createBoard();
        board.addRandomTile();
        board.addRandomTile();
        board.visualizeBoard(board.getBoard());
        while (!checkGameOver()) {
                board.setBoard(player.getInput());
                board.addRandomTile();
                board.visualizeBoard(board.getBoard());

        }

    }





};


#endif //INC_2048_GAME2048_H
