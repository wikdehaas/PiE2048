//
// Created by user on 8/11/2018.
//

#ifndef INC_2048_BOARD2048_H
#define INC_2048_BOARD2048_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Board2048 {
    vector<int> boardVector;
    bool gameOver;
    int totalScore;
    vector<int> tempScore;

    vector<int> checkEmpty(vector<int> v);
    void createBoard();

protected:
    const unsigned int SIZE = 4;

public:
    Board2048();

    void setBoard(vector<int> &v);

    vector<int> getBoard();

    void addRandomTile();

    void visualizeBoard(vector<int> v);

    void setGameOver(bool g);

    bool getGameOver();

    void setScore(int s);

    int getScore();

    void addScore(int score);

    void setTempScore(vector<int> &scoreVec);

    vector<int> getTempScore();
};


#endif //INC_2048_BOARD2048_H
