//
// Created by user on 8/11/2018.
//

#ifndef INC_2048_PLAYER_H
#define INC_2048_PLAYER_H

#include <iostream>
#include <vector>
#include <valarray>
#include "Update.h"

using namespace std;
/* The class Player has a name which can be set and gotten from it. It is the parent of subclasses HumanPlayer and
 * ComputerPlayer, which both have a different implementation of the virtual function getInput. The class Player
 * inherits from the class Update, from which it uses various functions in getInput, mainly to get possible next
 * boards and the scores and directions which go with the boards.
 *
 * Functions used in other classes/files:
 * Game2048: Player, getInput, setName, getName
 */

class Player : public Update {
    //private variables
    string name; //the name of a Player
public:
    //public functions
    Player() = default; //default constructor
    virtual vector<int> getInput(Board2048 &board2048);

    void setName(string &n);
    string getName();
};

/* The class ComputerPlayer is a sub class of Player. It overrides getInput and is implemented with a function that
 * determines the best possible directions for a board.
 *
 * Functions used in other classes/files:
 * Game2048: ComputerPlayer, getInput
 */

class ComputerPlayer : public Player {
    //private functions
    int nextStep(vector<int> &nextBoard);
    int boardValueFun(vector<int> currBoard, int score);
public:
    //public functions
    ComputerPlayer() = default; //default constructor
    vector<int> getInput(Board2048 &board2048) override;
};

/* The class HumanPlayer is a sub class of Player. It overrides getInput and is implemented with a function that
 * asks for a direction and uses it.
 *
 * Functions used in other classes/files:
 * Game2048: HumanPlayer, getInput
 */

class HumanPlayer : public Player {
public:
    //public functions
    HumanPlayer() = default; //default constructor
    vector<int> getInput(Board2048 &board2048) override;
};


#endif //INC_2048_PLAYER_H
