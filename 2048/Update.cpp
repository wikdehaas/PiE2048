#include "Update.h"
#include <vector>
#include <valarray>
#include <algorithm>


using namespace std;

//Constructor
Update::Update() {
    score = 0; //Initialize score
}

// --------------- Function which removes zeros from vector -------------------------------------------
/*  All zeroes from a vector are removed by using a for loop en putting the non-zero values in a new vector.
 * This new vector, without zeroes is returned.
 *
 * input:
 *      - vector of SIZE (column or row of the board)
 * Output:
 *      - vector without zero values.
 */

vector<int> Update::removeZeroes(vector<int> tempVec) {
    vector<int> emptyZeroes;
    for(auto i:tempVec) {
        if (i != 0) {
            emptyZeroes.push_back(i);
        }
    }
    return emptyZeroes;
}

// --------------- Function which shifts a vector -------------------------------------------
/*  This function shifts all non zero values to the left, if values are equal they are added to each other.
 * This is done by first removing the zeroes, merging values which are equal and next to each other. At the end the zeroes
 * are added again at the end of the vector.
 *
 * input:
 *      - vector of SIZE (column or row of the board)
 * Output:
 *      - vector of SIZE with all non-zero values at the beginning.
 */
vector<int> Update::shiftVector(vector<int> tempVec) {

    tempVec = removeZeroes(tempVec);
    for (int i = 0; i < (tempVec.size() - 1)&&!tempVec.empty(); i++) {
        if (tempVec[i] == tempVec[i + 1]) {
            tempVec[i] = tempVec[i] * 2;
            tempVec[i + 1] = 0;

            //addPoints is called to keep track of the points of 1 board.
            addPoints(tempVec[i]);
        }
    }
    // remove zeroes again and add them at the end of the vector.
    tempVec = removeZeroes(tempVec);
    tempVec.resize(SIZE);
    return tempVec;
}


// --------------- Function which updates matrix -------------------------------------------
/*  Function which shifts non zero values in  a matrix in a certain direction and merges values which are equal and
 * next to each other.
 * Input:
 *      - Matrix: the vector of the current board
 *      - direction: a char which corresponds to a certain direction
 * Output:
 *      - Updated Matrix: matrix with shifted values
 *
 * Note: Since Matrix is a vector, we use 2 for loops to acces each element in the
 */
vector<int> Update::updateMatrix(vector<int> matrix, char direction) {
    score = 0;
    vector<int> updatedMatrix (16,0) ;
    //Check for up or down movement
    if(direction=='w'||direction=='s'){
        for (int i = 0; i < SIZE; i++) {
            // create a temporary vector
            vector<int> tempVec(SIZE);
            for (unsigned j = 0; j < tempVec.size(); j++) {
                tempVec.at(j) = matrix[i + j * SIZE];
            }
            if (direction == 'w') {
                //for up movement shift the values
                tempVec = shiftVector(tempVec);
            } else {
                //for down movement flip vector, shift it, at the end flip it again
                reverse(tempVec.begin(), tempVec.end());
                tempVec = shiftVector(tempVec);
                reverse(tempVec.begin(), tempVec.end());
            }
            //Write the shifted vector to the updatedMatrix
            for (int j = 0; j != tempVec.size(); ++j) {
                updatedMatrix[i + j * SIZE] = tempVec[j];
            }
        }
        //Check for left or right movement
    }else if(direction=='a'||direction=='d') {
        for (int i = 0; i < SIZE; i++) {
            vector<int> tempVec(SIZE);
            for (unsigned j = 0; j < tempVec.size(); j++) {
                tempVec.at(j) = matrix[i * SIZE + j];
            }
            if (direction == 'a') {
                //for left movement shift the values
                tempVec = shiftVector(tempVec);
            } else {
                //for right movement flip vector, shift it, at the end flip it again
                reverse(tempVec.begin(), tempVec.end());
                tempVec = shiftVector(tempVec);
                reverse(tempVec.begin(), tempVec.end());
            }
            //Write the shifted vector to the updatedMatrix
            for (int j = 0; j != tempVec.size(); ++j) {
                updatedMatrix[i * SIZE + j] = tempVec[j];
            }
        }
    }
    return updatedMatrix;
}

// add points to the current score.
int Update::addPoints(int points){
    score += points;
    return score;

}

// returns the directions the player can move.
vector<char> Update::getDirections(){
    return validDirections;
}


// --------------- function which gets all possible outcomes of a board -------------------------------------------
/* This function will create the boards of all possible moves. Furthermore it will save the directions which can be
 * moved and the scores in that direction.
 * Input:
 *      - Instance board.
 *Output:
 *      - 2 dimensional vector with possible boards.
 */

vector< vector<int>> Update::getVectors(Board2048 &bo){
    const string ALLDIR = "wasd";
    validDirections.clear();
    vector<vector<int>> allMatrix;
    vector<int> scoreVec;
    vector<int> matrix = bo.getBoard(); // Current board

    // For loop to check all possible directions
    for (auto i : ALLDIR){
        vector<int> temp_mat = updateMatrix(matrix,i);
        // if the new matrix has changed, it's a valid move.
        if (temp_mat != matrix) {
            validDirections.push_back(i);
            allMatrix.push_back(temp_mat);
            scoreVec.push_back(score);
        }
    }

    //Write corresponding scores to scoreVec
    bo.setTempScore(scoreVec);
    // Check if valid directions is empty and player is game over
    if (validDirections.empty()) {
        bo.setGameOver(true);
    }

    // return possible boards
    return allMatrix;
}