//
// Created by user on 8/11/2018.
//

#ifndef INC_2048_BOARD2048_H
#define INC_2048_BOARD2048_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Game2048.h"

using namespace std;

class Board2048 : public Game2048 {
    unsigned int size;
    vector<int> boardVector;
    vector<int> emptyTileIndices;
    unsigned int newTileChance;

    vector<int> checkEmpty(vector<int> v) {
        vector<int> z;
        for (int i = 0; i<v.size();i++) {
            if (v[i]==0) {
                z.push_back(i);
            }
        }
        return z;
    }

public:
    void setBoardSize(unsigned const int s) {
        size = s;
    }

    int getBoardSize() {
        return size;
    }

    void setBoard(vector<int> v) {
        boardVector = v;
    }

    vector<int> getBoard() {
        return boardVector;
    }

    void createBoard() {
        boardVector.resize(size*size);
        fill(boardVector.begin(), boardVector.end(), 0);
    }

    void addRandomTile() {
        emptyTileIndices = checkEmpty(getBoard());
        srand(time(NULL));
        int sizeETI = emptyTileIndices.size();
        int indETI = rand() % sizeETI;
        int indBV = emptyTileIndices[indETI];
        newTileChance = rand() % sizeETI;
        boardVector[indBV] = (newTileChance <= 0.1*(double)sizeETI) ? 4 : 2;
    }

    void visualizeBoard(vector<int> v) {
        for (int i = 0; i < size; i++){
            for (int k = 0; k < size; k++) {
                cout << v[size*i+k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};


#endif //INC_2048_BOARD2048_H
