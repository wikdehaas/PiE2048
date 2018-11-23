//
// Created by user on 8/11/2018.
//

#ifndef INC_2048_UPDATE_H
#define INC_2048_UPDATE_H

#include <vector>
#include <algorithm>
#include <string>
#include "Board2048.h"

using namespace std;

class Update : public Board2048{
    // --------------- variables -------------------------------------------

    vector<char> validDirections;
    int score;

    // --------------- Function which shifts vector -------------------------------------------
    vector<int> shiftVector(vector<int> tempVec);

    // --------------- Function which updates matrix -------------------------------------------
    vector<int> updateMatrix(vector<int> matrix, char direction);

    int addPoints(int points);

protected:
    // --------------- Function which removes zeros from vector -------------------------------------------
    vector<int> removeZeroes(vector<int> tempVec);

public:
    Update();
    vector<char> getDirections();
    vector< vector<int>> getVectors(Board2048 &bo);
};


#endif //INC_2048_UPDATE_H
