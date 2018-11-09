//
// Created by user on 8/11/2018.
//

#include "Board2048.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
//#include "Game2048.h"

using namespace std;

//class Board2048 : public Game2048 {
//    unsigned int size;
//    vector<int> boardVector;
//    vector<int> emptyTileIndices;
//    unsigned int newTileChance;
//    Board2048::Board2048() {}
    Board2048::Board2048(const unsigned int SIZE) {
        Board2048::setBoardSize(SIZE);
        Board2048::createBoard();
        Board2048::addRandomTile();
        Board2048::addRandomTile();
        Board2048::visualizeBoard(Board2048::getBoard());
    }

    vector<int> Board2048::checkEmpty(vector<int> v) {
        vector<int> z;
        for (int i = 0; i<v.size();i++) {
            if (v[i]==0) {
                z.push_back(i);
            }
        }
        return z;
    }

//public:
    void Board2048::setBoardSize(const unsigned int s) {
        size = s;
    }

    int Board2048::getBoardSize() {
        return size;
    }

    void Board2048::setBoard(vector<int> v) {
        boardVector = v;
    }

    vector<int> Board2048::getBoard() {
        return boardVector;
    }

    void Board2048::createBoard() {
        boardVector.resize(size*size);
        fill(boardVector.begin(), boardVector.end(), 0);
    }

    void Board2048::addRandomTile() {
        emptyTileIndices = checkEmpty(getBoard());
        srand(time(NULL));
        int sizeETI = emptyTileIndices.size();
        int indETI = rand() % sizeETI;
        int indBV = emptyTileIndices[indETI];
        newTileChance = rand() % sizeETI;
        boardVector[indBV] = (newTileChance <= 0.1*(double)sizeETI) ? 4 : 2;
    }

    void Board2048::visualizeBoard(vector<int> v) {
        for (int i = 0; i < size; i++){
            for (int k = 0; k < size; k++) {
                cout << v[size*i+k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
//};