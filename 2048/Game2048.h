//
// Created by user on 8/11/2018.
//

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
    Player* player;
    const int maxNameLength = 15;

    //Private functions
    Player* choosePlayerType(HumanPlayer* HP, ComputerPlayer* CP);

public:
    Game2048();
    void runGame();
};

#endif //INC_2048_GAME2048_H
