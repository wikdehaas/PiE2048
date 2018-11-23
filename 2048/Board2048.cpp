//
// Created by user on 8/11/2018.
//

#include "Board2048.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

//-------------------- Constructor -----------------------
//Creates the board, adds 1 random tile and sets the score to 0 upon construction of the board
Board2048::Board2048() {
    Board2048::createBoard();
    Board2048::addRandomTile();
    Board2048::setScore(0);
}

//------------------- checkEmpty -------------------------
/*CHECKEMPTY checks which tiles from the board vector are zero and returns their indices
 * Input:
 *      - boardVec: vector with integers of size SIZE^2, contains the values of the current tiles
 *
 * Output:
 *      - indZeroTiles: vector with integers of variable size, contains the indices of all zero tiles
 */
vector<int> Board2048::checkEmpty(vector<int> boardVec) {
    vector<int> indZeroTiles;
    //For-loop to check every tile (element from the board vector)
    for (int i = 0; i<boardVec.size();i++) {
        //If-loop to check if tile is zero
        if (boardVec[i]==0) {
            indZeroTiles.push_back(i); //Push back index of zero tile to indZeroTiles vector
        }
    }
    return indZeroTiles;
}

//------------------- createBoard ------------------------
/* CREATEBOARD creates the board vector with the right size and fills it with zeroes
 * Input: none
 *
 * Output: none
 */
void Board2048::createBoard() {
    boardVector.resize(SIZE*SIZE); //Create board vector of appropriate size
    fill(boardVector.begin(), boardVector.end(), 0); //Fill board vector with zeroes
}

//----------------- addRandomTile ------------------------
/* ADDRANDOMTILE adds a random tile (value 90% chance of 2 and 10% 4) in a random empty (value 0) spot
 * Input: none
 *
 * Output: none
 */
void Board2048::addRandomTile() {
    vector<int> emptyTileIndices = checkEmpty(getBoard()); //Call checkEmpty to find which tiles are empty
    srand((unsigned)(time(nullptr))); //Create a seed for pseudo-random number generator
    int sizeETI = emptyTileIndices.size(); //Number of empty tiles
    int indETI = rand() % sizeETI; //Random vector index from 0 to number of empty tiles (end of emptyTileIndices)
    int indBV = emptyTileIndices[indETI]; //Index of randomly chosen empty tile
    int newTileChance = rand() % sizeETI; //Random value from same range
    boardVector[indBV] = (newTileChance <= 0.1*(double)sizeETI) ? 4 : 2; //10% chance for new tile being 4, otherwise 2
}

//----------------- visualizeBoard ---------------------
/* VISUALIZEBOARD visuzalizes the current board by outputting it to the console command
 * Input:
 *      - boardVec: vector with integers of size SIZE^2, contains the values of the current tiles
 *
 * Output: none
 */
void Board2048::visualizeBoard(vector<int> boardVec) {
    const int maxSpaces = 5; //Max spaces reserved for tile value, 2048 requires 4 spaces and an extra space is added

    //For-loop that iterates over the rows
    for (int i = 0; i < SIZE; i++){
        //For-loop that iterates over the columns
        for (int k = 0; k < SIZE; k++) {
            cout << left << setw(maxSpaces) << boardVec[SIZE*i+k]; //Left-aligned output of the tile value to console
        }
        cout << endl; //Line break at end of row
    }
    cout << endl; //Line break at end of total matrix
}

//----------------- setBoard ---------------------
/* SETBOARD is the setter for the private vector boardVector
 * Input:
 *      - boardVec: vector with integers of size SIZE^2, contains the values of the current tiles
 *
 * Output: none
 */
void Board2048::setBoard(vector<int> &boardVec) {
    boardVector = boardVec;
}

//----------------- getBoard ---------------------
/* GETBOARD is the getter for the private vector boardVector
 * Input: none
 *
 * Output:
 *      - boardVector: vector with integers of size SIZE^2, contains the values of the current tiles
 */
vector<int> Board2048::getBoard() {
    return boardVector;
}

//----------------- setGameOver ---------------------
/* SETGAMEOVER is the setter for the private boolean gameOver
 * Input:
 *      - go: boolean that sets the game over state
 *
 * Output: none
 */
void Board2048::setGameOver(bool go){
    gameOver = go;
}

//----------------- getGameOver ---------------------
/* GETGAMEOVER is the getter for the private boolean gameOver
 * Input: none
 *
 * Output:
 *      - gameOver: boolean that shows if you are game over
 */
bool Board2048::getGameOver(){
    return gameOver;
}

//----------------- setScore ---------------------
/* SETSCORE is the setter for the private integer totalScore
 * Input:
 *      - score: integer that sets the total score
 *
 * Output: none
 */
void Board2048::setScore( int score) {
    totalScore = score;
}

//----------------- addScore ---------------------
/* ADDSCORE adds the score for a single move to totalScore
 * Input:
 *      - score: integer with the score of a single, made move
 *
 * Output: none
 */
void Board2048::addScore(int score) {
    totalScore += score;
}

//----------------- getScore ---------------------
/* GETSCORE is the getter for the private integer totalScore
 * Input: none
 *
 * Output:
 *      - totalScore: integer with the total score
 */
int Board2048::getScore() {
    return totalScore;
}

//----------------- setTempScore ---------------------
/* SETTEMPSCORE is the setter for the private vector tempScore
 * Input:
 *      - scoreVec: vector with integers of variable size (max 4), contains the scores for all possible moves
 *
 * Output: none
 */
void Board2048::setTempScore(vector<int> &scoreVec) {
    tempScore = scoreVec;
}

//----------------- getTempScore ---------------------
/* GETTEMPSCORE is the getter for the private vector tempScore
 * Input: none
 *
 * Output:
 *      - tempScore: vector with integers of variable size (max 4), contains the scores for all possible moves
 */
vector<int> Board2048::getTempScore() {
    return tempScore;
}
