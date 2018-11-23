//
// Created by user on 8/11/2018.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Game2048.h"

using namespace std;

Game2048::Game2048() {
    player = new Player;
}

Player* Game2048::choosePlayerType(HumanPlayer* HP, ComputerPlayer* CP) {
    cout << "What is the player type? Computer or human?" << endl;
    string inputPlayerType;
    getline(cin,inputPlayerType);

    if (inputPlayerType == "computer" || inputPlayerType == "Computer") {
        cin.ignore();
        player = CP;
        string compName = "Computer";
        player->setName(compName);
        cout << "Computer chosen." << endl;
    }
    else {
        if(inputPlayerType == "human" || inputPlayerType == "Human"){
            cout << "Human player chosen." << endl;
        }
        else {

            cout << "Unknown input given. Human player assumed" << endl;
        }
        player = HP;
        cout << "Type your name (max 15 char): " << endl;
        bool goodInput = false;
        while (!goodInput) {
            string playerName;
            cin.ignore();
            getline(cin, playerName);
            replace(playerName.begin(),playerName.end(),' ','_');
            cout << playerName << endl;
            if (playerName.size() <= maxNameLength) {
                goodInput = true;
                player->setName(playerName);
            }
            else {
                cout << "Character limit exceeded (> " << maxNameLength << ")" << endl;
            }

        }
    }
    return player;
}

void Game2048::runGame() {
    ComputerPlayer CP;
    HumanPlayer HP;
    Highscore HS(maxNameLength);
    HS.viewHighscore();
    player = choosePlayerType(&HP, &CP);
    Board2048 board;
    board.setGameOver(false);


    while (!board.getGameOver()) {
        board.addRandomTile();
        board.visualizeBoard(board.getBoard());
        vector<int> currBoard = player->getInput(board);
        board.setBoard(currBoard);
    }

    cout << "Game over!" << endl;
    cout << "Your score is " << board.getScore() << endl;
    HS.addHighscore(player->getName(),board.getScore());
    HS.viewHighscore();
}