//
// Created by user on 8/11/2018.
//

#include "Board2048.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

    Board2048::Board2048() {
        Board2048::createBoard();
        Board2048::addRandomTile();
        Board2048::setScore(0);
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

    void Board2048::setBoard(vector<int> &v) {
        boardVector = v;
    }

    vector<int> Board2048::getBoard() {
        return boardVector;
    }

    void Board2048::createBoard() {
        boardVector.resize(SIZE*SIZE);
        fill(boardVector.begin(), boardVector.end(), 0);
    }

    void Board2048::addRandomTile() {
        vector<int> emptyTileIndices = checkEmpty(getBoard());
        srand((unsigned)(time(nullptr)));
        int sizeETI = emptyTileIndices.size();
        int indETI = rand() % sizeETI;
        int indBV = emptyTileIndices[indETI];
        int newTileChance = rand() % sizeETI;
        boardVector[indBV] = (newTileChance <= 0.1*(double)sizeETI) ? 4 : 2;
    }

    void Board2048::visualizeBoard(vector<int> v) {
        const int maxSpaces = 5;
        for (int i = 0; i < SIZE; i++){
            for (int k = 0; k < SIZE; k++) {
                cout << v[SIZE*i+k];
                for(int j =0;j<(maxSpaces-to_string(v[SIZE*i+k]).length());j++)
                    cout<<" ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void Board2048::setGameOver(bool go){
        gameOver = go;
    }

    bool Board2048::getGameOver(){
        return gameOver;
    }

    void Board2048::setScore( int s) {
        totalScore = s;
    }

    void Board2048::addScore(int score) {
        totalScore += score;
    }

    int Board2048::getScore() {
        return totalScore;
    }

    void Board2048::setTempScore(vector<int> &scoreVec) {
        tempScore = scoreVec;
    }

    vector<int> Board2048::getTempScore() {
        return tempScore;
    }
