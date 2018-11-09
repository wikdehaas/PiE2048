//
// Created by user on 8/11/2018.
//

#ifndef INC_2048_BOARD2048_H
#define INC_2048_BOARD2048_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
//#include "Game2048.h"

using namespace std;

class Board2048 {
//public:

    unsigned int size;
    vector<int> boardVector;
    vector<int> emptyTileIndices;
    unsigned int newTileChance;

    vector<int> checkEmpty(vector<int> v);

public:
    Board2048() = default;
    Board2048(const unsigned int);
    void setBoardSize(unsigned const int s);

    int getBoardSize();

    void setBoard(vector<int> v);

    vector<int> getBoard();

    void createBoard();

    void addRandomTile();

    void visualizeBoard(vector<int> v);
};


#endif //INC_2048_BOARD2048_H
