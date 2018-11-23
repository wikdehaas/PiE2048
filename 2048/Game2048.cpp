//
// Created by user on 8/11/2018.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Game2048.h"

using namespace std;

//----------------------- Constructor -----------------------
Game2048::Game2048() {
    player = new Player; //Initialize player
}

//--------------------- choosePlayerType --------------------
/* CHOOSEPLAYERTYPE determines the type of player; computer or human and returns a pointer to the appropriate instance.
 * Input:
 *      - HumanPlayer* HP: pointer to an instance of class HumanPlayer
 *      - ComputerPlayer* CP: pointer to an instance of class ComputerPlayer
 *
 * Output:
 *      - Player* player: pointer to the instance of the chosen player type
 */
Player* Game2048::choosePlayerType(HumanPlayer* HP, ComputerPlayer* CP) {
    //Ask user for player type input
    cout << "What is the player type? Computer or human?" << endl;
    string inputPlayerType;
    getline(cin,inputPlayerType);

    //If-loop to process user input
    if (inputPlayerType == "computer" || inputPlayerType == "Computer") { //Check if user wants computer
        player = CP; //Point player to instance of class ComputerPlayer
        string compName = "Computer"; //Computer name for highscore
        player->setName(compName); //Assign name to instance
        cout << "Computer chosen." << endl;
    }
    else {
        if(inputPlayerType == "human" || inputPlayerType == "Human"){ //Check if user wants human
            cout << "Human player chosen." << endl;
        }
        else { //Fallback in case of invalid input
            cout << "Unknown input given. Human player assumed" << endl;
        }
        player = HP; //Point player to instance of class HumanPlayer

        //Ask user for name to be used in highscore
        cout << "Type your name (max 15 char): " << endl;
        bool goodInput = false; //Initialize

        //While-loop to keep asking for a valid name
        while (!goodInput) {
            string playerName;
            cin.ignore(); //Ignore overflow user input from previous getline (inputPlayerType)
            getline(cin, playerName);
            replace(playerName.begin(),playerName.end(),' ','_'); //Replace spaces with underscores

            //If-loop to determine if specified name is valid (name length)
            if (playerName.size() < maxNameLength) {
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


//----------------------- runGame ----------------------
/* RUNGAME is the main function that executes the game and calls the appropriate subfunctions and classes
 * Input: none
 *
 * Output: none
 */
void Game2048::runGame() {
    ComputerPlayer CP; //Create ComputerPlayer instance
    HumanPlayer HP; //Create HumanPlayer instance
    Highscore HS(maxNameLength); //Create Highscore instance and specify max name length
    HS.viewHighscore(); //Call viewHighscore to ask user the current highscore should be shown
    player = choosePlayerType(&HP, &CP); //Call choosePlayerType to determine which player type the user wants
    Board2048 board; //Create Board2048 instance
    board.setGameOver(false); //Initialize game over

    //While-loop to keep executing game steps until game over
    while (!board.getGameOver()) {
        board.addRandomTile(); //Call addRandomTile to add a random tile in a random (empty) spot
        board.visualizeBoard(board.getBoard()); //Call visualizeBoard to visualize the current board
        vector<int> currBoard = player->getInput(board); //Create the board of the next step with the new input
        board.setBoard(currBoard); //Call setBoard to update the board with the new board
    }

    cout << "Game over!" << endl;
    cout << "Your score is " << board.getScore() << endl;
    HS.addHighscore(player->getName(),board.getScore()); //Call addHighscore to add new name and score
    HS.viewHighscore(); //Call viewHighscore to ask user the current highscore should be shown
}