//
// Created by user on 8/11/2018.
//

/* The class Board2048 mainly governs the current tiles on the board (boardVector), the game over state (gameOver) and
 * the total score (totalScore). It also contains the constant integer SIZE which dictates the board size.
 *
 * Functions used in other classes/files:
 * Game2048: setGameOver, addRandomTile, visualizeBoard, setBoard, getScore
 * Update: getBoard, setTempScore, setGameOver
 * Player: getTempScore, getBoard, addScore
 */

#ifndef INC_2048_BOARD2048_H
#define INC_2048_BOARD2048_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Board2048 {
    //Private variables
    vector<int> boardVector; //The elements on the board in one vector (rows added after each other)
    bool gameOver; //Game over check
    int totalScore; //Total score for the current board
    vector<int> tempScore; //Temporary scores for all currently possible moves

    //Private functions
    vector<int> checkEmpty(vector<int> boardVec);
    void createBoard();

protected:
    //Protected variables
    const unsigned int SIZE = 4; //Size of the square board: SIZE x SIZE

public:
    //Public functions
    Board2048(); //Constructor
    void addRandomTile();
    void visualizeBoard(vector<int> boardVec);
    void addScore(int score);

    //Public Setters & Getters
    void setBoard(vector<int> &boardVec);
    vector<int> getBoard();

    void setGameOver(bool go);
    bool getGameOver();

    void setScore(int score);
    int getScore();

    void setTempScore(vector<int> &scoreVec);
    vector<int> getTempScore();
};


#endif //INC_2048_BOARD2048_H
