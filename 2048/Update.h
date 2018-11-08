//
// Created by user on 8/11/2018.
//

#ifndef INC_2048_UPDATE_H
#define INC_2048_UPDATE_H

#include <vector>
#include <algorithm>
#include "Board2048.h"

using namespace std;

class Update : public Board2048{
    // --------------- variables -------------------------------------------

    char ALLDIR[5] = "wasd";
    vector<int> score_vec;
    vector<char> valid_directions;
    vector< vector<int>> allMatrix;
    vector<int> temp_mat;
    vector<int> matrix;
    int score = 0;

    unsigned int SIZE;


    // --------------- Function which removes zeros from vector -------------------------------------------
    vector<int> removeZeroes(vector<int> tempVec) {
        for (int i = 0; i < tempVec.size(); i++) {
            if (tempVec[i] == 0) {
                tempVec.erase(tempVec.begin() + i);
            }
        }
        return tempVec;
    }
    // --------------- Function which shifts vector -------------------------------------------
    vector<int> shiftVector(vector<int> tempVec) {

        tempVec = removeZeroes(tempVec);
        for (unsigned j = 0; j < (tempVec.size() - 1); j++) {
            int points = 0;
            if (tempVec[j] == tempVec[j + 1]) {
                tempVec[j] = tempVec[j] * 2;
                tempVec[j + 1] = 0;
                addPoint(points + tempVec[j]);
            }
        }
        tempVec = removeZeroes(tempVec);
        tempVec.resize(SIZE);
        return tempVec;
    }

    // --------------- Function which updates matrix -------------------------------------------
    vector<int> updateMatrix(vector<int> matrix, char direction){
        score = 0;
        switch(direction) {
            case 'w':
                for (int i = 0; i < SIZE; i++) {
                    vector<int> tempVec(SIZE);
                    for (unsigned j = 0; j < tempVec.size(); j++) {
                        tempVec.at(j) = matrix[i + j * SIZE];
                    }
                    tempVec = shiftVector(tempVec);
                    for (int j = 0; j != tempVec.size(); ++j) {
                        matrix[i + j * SIZE] = tempVec[j];
                    }
                }
                return matrix;
            case 'a':
                for (int i = 0; i < SIZE; i++) {
                    vector<int> tempVec(SIZE);
                    for (unsigned j = 0; j < tempVec.size(); j++) {
                        tempVec.at(j) = matrix[i * SIZE + j];
                    }
                    tempVec = shiftVector(tempVec);
                    for (int j = 0; j != tempVec.size(); ++j) {
                        matrix[i * SIZE + j] = tempVec[j];
                    }
                }
                return matrix;
            case 's':
                for (int i = 0; i < SIZE; i++) {

                    vector<int> tempVec(SIZE);
                    for (unsigned j = 0; j < tempVec.size(); j++) {
                        tempVec.at(j) = matrix[i + j * SIZE];
                    }
                    std::reverse(tempVec.begin(), tempVec.end());
                    tempVec = shiftVector(tempVec);
                    std::reverse(tempVec.begin(), tempVec.end());

                    for (int j = 0; j != tempVec.size(); ++j) {
                        matrix[i + j * SIZE] = tempVec[j];
                    }

                }
                return matrix;
            case 'd':
                for (int i = 0; i < SIZE; i++) {
                    vector<int> tempVec(SIZE);
                    for (unsigned j = 0; j < tempVec.size(); j++) {
                        tempVec.at(j) = matrix[i * SIZE + j];
                    }

                    std::reverse(tempVec.begin(), tempVec.end());
                    tempVec = shiftVector(tempVec);
                    std::reverse(tempVec.begin(), tempVec.end());

                    for (int j = 0; j != tempVec.size(); ++j) {
                        matrix[i * SIZE + j] = tempVec[j];
                    }
                }
                return matrix;
            default:
                return matrix;
        }
    }

    int addPoint(int points){
        score = score + points;
        return score;

    }
    int counter;
public:

    vector<char> getDirections(){
        return valid_directions;
    }

    vector< vector<int>> getVectors(Board2048 bo){
        SIZE = bo.getBoardSize();
        matrix = bo.getBoard();
        for(auto i:matrix)
            cout<<i<<" ";
        counter = 0;
        valid_directions.clear();
        allMatrix.clear();
        score_vec.clear();

        for (int i = 0; i < SIZE; i++){

            temp_mat = updateMatrix( matrix, ALLDIR[i]);

            if (temp_mat == matrix){

            }else{

                valid_directions.push_back(ALLDIR[i]);
                allMatrix.push_back(temp_mat);

                score_vec.push_back(score);
                counter++;
            }
        }
        return allMatrix;
    }

    vector<int> getPoints(){
        return score_vec;
    }
};


#endif //INC_2048_UPDATE_H
