//
// Created by user on 8/11/2018.
//

#include "Game2048.h"
#include <iostream>
#include <string>
#include <vector>
//#include "Player.h"
//#include "Board2048.h"

using namespace std;

//class Board2048;
//class Player;
//class ComputerPlayer;
//class HumanPlayer;

//class Game2048 {
    Game2048::Game2048() {
//        cout << "Game created" << endl;
    }

    unsigned const int SIZE = 4;

//    bool gameOver = false;
//    string inputPlayerType;
//    vector<char> posDir;

    Player* Game2048::choosePlayerType() {
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

//public:
    void Game2048::runGame() {
        cout << 1 << endl;
        HumanPlayer HP;
        Player* player = &HP;
        cout << player << endl;
        cout << 2 << endl;
        Board2048 board(SIZE);


//        board.setBoardSize(SIZE);
//        board.createBoard();
//        board.addRandomTile();
//        board.addRandomTile();
//        board.visualizeBoard(board.getBoard());
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


//};