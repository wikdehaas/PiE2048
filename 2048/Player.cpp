//
// Created by user on 8/11/2018.
//

#include "Player.h"
#include <iostream>
#include <vector>
#include <valarray>
#include <algorithm>
#include <iterator>

using namespace std;

vector<int> Player::getInput(Board2048 &bo){
    vector<int> v;
    return v;
}

string Player::getName() {
    return name;
}

void Player::setName(string &n){
    name = n;
}

int ComputerPlayer::boardValueFun(vector<int> currBoard, int score) {
    vector<int> cornerValues = {currBoard[0], currBoard[SIZE-1], currBoard[SIZE*SIZE-SIZE], currBoard[SIZE*SIZE-1]};
    int weighFactorCV = 10;
    auto maxElementIterator = max_element(cornerValues.begin(), cornerValues.end()); //iterator
    int maxElement = *maxElementIterator;

    int boardValue = weighFactorCV*maxElement;

    int maxIndex = distance(cornerValues.begin(),maxElementIterator);

    double weighFactorNT = 0.3;
    if (maxIndex == 0){
        boardValue += (int)(weighFactorNT*(currBoard[1]+currBoard[SIZE]+currBoard[SIZE+1]));
    }
    else if (maxIndex == SIZE-1) {
        boardValue += (int)(weighFactorNT*(currBoard[SIZE-2]+currBoard[SIZE-1+SIZE]+currBoard[SIZE-2+SIZE]));
    }
    else if (maxIndex == SIZE*SIZE-SIZE) {
        boardValue += (int)(weighFactorNT*(currBoard[SIZE*SIZE-SIZE+1]+currBoard[SIZE*SIZE-2*SIZE]+currBoard[SIZE*SIZE-2*SIZE+1]));
    }
    else if (SIZE*SIZE-1) {
        boardValue += (int)(weighFactorNT*(currBoard[SIZE*SIZE-2]+currBoard[SIZE*SIZE-SIZE-1]+currBoard[SIZE*SIZE-SIZE-2]));
    }


    vector<int> nonZeroElem = removeZeroes(currBoard);
    int weighFactorNZE = maxElement/(SIZE*SIZE);
    boardValue -= weighFactorNZE*nonZeroElem.size();

    int weighFactorS = 1;
    boardValue += weighFactorS*score;

    return boardValue;
}

int ComputerPlayer::nextStep(vector<int> &nextBoard) {
    Board2048 tempBoard;
    tempBoard.setBoard(nextBoard);
    vector<vector<int>> vecNextOptions = getVectors(tempBoard);
    vector<int> scoreNextOptions = tempBoard.getTempScore();
    vector<int> nextBoardChoice;
    nextBoardChoice.reserve(vecNextOptions.size());
    for (int i = 0; i<vecNextOptions.size();i++) {
        nextBoardChoice.push_back(boardValueFun(vecNextOptions[i],scoreNextOptions[i]));
    }
    int bestNextStep = *max_element(nextBoardChoice.begin(), nextBoardChoice.end());
    return bestNextStep;
}

vector<int> ComputerPlayer::getInput(Board2048 &bo) {
    vector<vector<int>> vecOptions = getVectors(bo);
    vector<int> scoreOptions = bo.getTempScore();

    if (vecOptions.empty()){
        return bo.getBoard();
    }

    vector<int> boardChoice;

    for (int i = 0;i<vecOptions.size();i++) {
        boardChoice.push_back(boardValueFun(vecOptions[i],scoreOptions[i]));
        int bestNextStep = nextStep(vecOptions[i]);
        double weighFactorNS = 0.7;
        boardChoice[i] += (int)(weighFactorNS*bestNextStep);
    }

    int index = distance(boardChoice.begin(),max_element(boardChoice.begin(), boardChoice.end()));

    int score = scoreOptions[index];
    bo.addScore(score);
    return vecOptions[index];
}

vector<int> HumanPlayer::getInput(Board2048 &bo){
    bool goodInput = false;
    string c;
    int index = 0;
    vector<vector<int>> vecOptions = getVectors(bo);
    vector<char> dirOptions = getDirections();
    vector<int> scoreOptions = bo.getTempScore();

    if (vecOptions.empty()){
        return bo.getBoard();
    }

    cout << "Input your wanted directions! (w,a,s,d)" << endl;
    while (!goodInput) {
        getline(cin,c);
        if (c[0] != 'w' && c[0] != 'a' && c[0] != 's' && c[0] != 'd') {
            cout << "This is not a correct input!" << endl;
        } else if (find(dirOptions.begin(), dirOptions.end(), c[0]) != dirOptions.end()){
            index = distance(dirOptions.begin(), find(dirOptions.begin(), dirOptions.end(), c[0]));
            int score = scoreOptions[index];
            bo.addScore(score);
            goodInput = true;
        } else {
            cout << "This direction does not move any number" << endl;
            goodInput = false;
        }
    }
    return vecOptions[index];
}