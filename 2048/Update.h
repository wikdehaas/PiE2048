//
// Created by user on 8/11/2018.
//

/* The class Update mainly governs the moving and updating of the board for all possible directions. Its functions shift
 * the tiles, add the tiles together and keep the score. It also checks if the game is over when there are no possible
 * directions to shift to.
 * Update inherits the class Board2048 and is inherited by the class Player.
 *
 * Functions used in other classes/files:
 * Player: getDirections, getVectors, removeZeroes
 */

#ifndef INC_2048_UPDATE_H
#define INC_2048_UPDATE_H

#include <vector>
#include <algorithm>
#include <string>
#include "Board2048.h"

using namespace std;

class Update : public Board2048{
private:
    //Private variables
    vector<char> validDirections; //Character vector with the possible directions w, a, s, and/or d
    int score; //Integer with the score for the current move

    //Private functions
    vector<int> shiftVector(vector<int> tempVec);
    vector<int> updateMatrix(vector<int> matrix, char direction);
    int addPoints(int points);

protected:
    //Protected functions
    vector<int> removeZeroes(vector<int> tempVec);

public:
    //Public functions
    Update(); //Constructor
    vector<char> getDirections();
    vector< vector<int>> getVectors(Board2048 &bo);
};


#endif //INC_2048_UPDATE_H
