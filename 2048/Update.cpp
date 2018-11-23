//
// Created by user on 8/11/2018.
//

#include "Update.h"
#include <vector>
#include <valarray>
#include <algorithm>


using namespace std;

Update::Update() {
    score = 0;
}

// --------------- Function which removes zeros from vector -------------------------------------------

vector<int> Update::removeZeroes(vector<int> tempVec) {
    vector<int> emptyZeroes;
    for(auto i:tempVec) {
        if (i != 0) {
            emptyZeroes.push_back(i);
        }
    }
    return emptyZeroes;
}
// --------------- Function which shifts vector -------------------------------------------
vector<int> Update::shiftVector(vector<int> tempVec) {

    tempVec = removeZeroes(tempVec);
    for (int i = 0; i < (tempVec.size() - 1)&&!tempVec.empty(); i++) {
        if (tempVec[i] == tempVec[i + 1]) {
            tempVec[i] = tempVec[i] * 2;
            tempVec[i + 1] = 0;
            addPoints(tempVec[i]);
        }
    }
    tempVec = removeZeroes(tempVec);
    tempVec.resize(SIZE);
    return tempVec;
}

// --------------- Function which updates matrix -------------------------------------------
vector<int> Update::updateMatrix(vector<int> matrix, char direction) {
    score = 0;
    if(direction=='w'||direction=='s'){
        for (int i = 0; i < SIZE; i++) {
            vector<int> tempVec(SIZE);
            for (unsigned j = 0; j < tempVec.size(); j++) {
                tempVec.at(j) = matrix[i + j * SIZE];
            }
            if (direction == 'w') {
                tempVec = shiftVector(tempVec);
            } else {
                std::reverse(tempVec.begin(), tempVec.end());
                tempVec = shiftVector(tempVec);
                std::reverse(tempVec.begin(), tempVec.end());
            }
            for (int j = 0; j != tempVec.size(); ++j) {
                matrix[i + j * SIZE] = tempVec[j];
            }
        }
    }else if(direction=='a'||direction=='d') {
        for (int i = 0; i < SIZE; i++) {
            vector<int> tempVec(SIZE);
            for (unsigned j = 0; j < tempVec.size(); j++) {
                tempVec.at(j) = matrix[i * SIZE + j];
            }
            if (direction == 'a') {
                tempVec = shiftVector(tempVec);
            } else {
                std::reverse(tempVec.begin(), tempVec.end());
                tempVec = shiftVector(tempVec);
                std::reverse(tempVec.begin(), tempVec.end());
            }
            for (int j = 0; j != tempVec.size(); ++j) {
                matrix[i * SIZE + j] = tempVec[j];
            }
        }
    }
    return matrix;
}

int Update::addPoints(int points){
    score += points;
    return score;

}

vector<char> Update::getDirections(){
    return validDirections;
}

vector< vector<int>> Update::getVectors(Board2048 &bo){
    const string ALLDIR = "wasd";
    validDirections.clear();
    vector<vector<int>> allMatrix;
    vector<int> scoreVec;
    vector<int> matrix = bo.getBoard();
    for (auto i : ALLDIR){
        vector<int> temp_mat = updateMatrix(matrix,i);
        if (temp_mat != matrix) {
            validDirections.push_back(i);
            allMatrix.push_back(temp_mat);
            scoreVec.push_back(score);
        }
    }
    bo.setTempScore(scoreVec);
    if (validDirections.empty()) {
        bo.setGameOver(true);
    }

    return allMatrix;
}