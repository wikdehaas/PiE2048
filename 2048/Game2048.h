//
// Created by user on 8/11/2018.
//

/* The class Game2048 runs the game and calls the appropriate classes and functions. It contains the player type pointer
 * (player) and the maximum name length (maxNameLength).
 *
 * Functions used in other classes/files:
 * main: runGame
 */

#ifndef INC_2048_GAME2048_H
#define INC_2048_GAME2048_H

#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "Highscore.h"

using namespace std;

class Game2048 {
    //Private variables
    Player* player; //Player pointer
    const int maxNameLength = 15; //Max character length of name

    //Private functions
    Player* choosePlayerType(HumanPlayer* HP, ComputerPlayer* CP);

public:
    //Public functions
    Game2048(); //Constructor
    void runGame();
};

#endif //INC_2048_GAME2048_H
