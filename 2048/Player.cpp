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

//--------------------getInput----------------------------------------
//GETINPUT in Player initializes a virtual getInput which is overridden by ComputerPlayer and HumanPlayer
vector<int> Player::getInput(Board2048 &bo){
    //initialize a return value which is never called
    vector<int> v;
    return v;
}

//---------------------getName-------------------------------
//GETNAME returns the name of the player
/* Input:
 *      - none
 * Output:
 *      - string name: the name of the Player
 */
string Player::getName() {
    return name;
}

//---------------------setName-------------------------------
//SETNAME sets the name of a Player to the given namePlayer
/* Input:
 *      - string &namePlayer: name of the player
 * Output:
 *      - none
 */
void Player::setName(string &namePlayer){
    name = namePlayer;
}
//--------------------- boardValueFun -------------------------
//BOARDVALUEFUN: This function gives a value to a move, which is used to determine how good the move is.
/* Input:
 *      - vector<int> currBoard: the board you check the value for
 *      - int score: the score you got with the made move
 * Output:
 *      - int boardValue: the value given to a move, used to determine the best move
 */
int ComputerPlayer::boardValueFun(vector<int> currBoard, int score) {
    vector<int> cornerValues = {currBoard[0], currBoard[SIZE-1], currBoard[SIZE*SIZE-SIZE], currBoard[SIZE*SIZE-1]};
    int weighFactorCV = 10; //weight factor corner values
    //get maximum value of the corners
    auto maxElementIterator = max_element(cornerValues.begin(), cornerValues.end()); //iterator
    int maxElement = *maxElementIterator;
    //add influence corner values to total boardValue
    int boardValue = weighFactorCV*maxElement;
    //get index of the maximum corner value
    int maxIndex = distance(cornerValues.begin(),maxElementIterator);

    double weighFactorNT = 0.3; //weight factor neighbor tiles
    //For the maximum corner, add the influence of the neighboring tiles to boardValue
    switch (maxIndex){
        case 0:
            boardValue += (int)(weighFactorNT*(currBoard[1]+currBoard[SIZE]+currBoard[SIZE+1]));
            break;
        case 1:
            boardValue += (int)(weighFactorNT*(currBoard[SIZE-2]+currBoard[SIZE-1+SIZE]+currBoard[SIZE-2+SIZE]));
            break;
        case 2:
            boardValue += (int)(weighFactorNT*(currBoard[SIZE*SIZE-SIZE+1]+currBoard[SIZE*SIZE-2*SIZE]+currBoard[SIZE*SIZE-2*SIZE+1]));
            break;
        default:
            boardValue += (int)(weighFactorNT*(currBoard[SIZE*SIZE-2]+currBoard[SIZE*SIZE-SIZE-1]+currBoard[SIZE*SIZE-SIZE-2]));
    }

    //get the amount of nonzero elements
    vector<int> nonZeroElem = removeZeroes(currBoard);
    int weighFactorNZE = maxElement/(SIZE*SIZE); //weight factor non zero elements
    //subtract influence non zero elements from boardValue
    boardValue -= weighFactorNZE*nonZeroElem.size();
    int weighFactorS = 1; //weight factor score for move
    //add influence score to boardValue
    boardValue += weighFactorS*score;
    return boardValue;
}

//-------------------nextStep----------------------------------
//NEXTSTEP checks the highest value of a move two steps ahead in time given a possible board nextBoard which is one
//step ahead in time.
/* Input:
 *      - vector<int> &nextBoard: The board of a possible next move
 * Output:
 *      - int bestNextStep: the value of the best next step given a possible next move
 */
int ComputerPlayer::nextStep(vector<int> &nextBoard) {
    Board2048 tempBoard; //initialize a temporary board
    //set the temporary board to nextBoard
    tempBoard.setBoard(nextBoard);
    vector<vector<int>> vecNextOptions = getVectors(tempBoard); //get vectors of the next options
    vector<int> scoreNextOptions = tempBoard.getTempScore(); //get the scores of next options
    vector<int> nextBoardChoice; //initialize nextBoardChoice
    //reserve memory for nextBoardChoice
    nextBoardChoice.reserve(vecNextOptions.size());
    //For every next board choice, determine the boardValue
    for (int i = 0; i<vecNextOptions.size();i++) {
        nextBoardChoice.push_back(boardValueFun(vecNextOptions[i],scoreNextOptions[i]));
    }
    //get the best value of the next steps and return it
    int bestNextStep = *max_element(nextBoardChoice.begin(), nextBoardChoice.end());
    return bestNextStep;
}

//------------------------getInput------------------------------
//GETINPUT in ComputerPlayer determines the "best" move and returns it as input value for the Computer
/* Input:
 *      - Board2048 &board: the current board on which the next "best" move is found
 * Output:
 *      - vector<int> vecOptions[index]: the vector of the chosen next board
 */
vector<int> ComputerPlayer::getInput(Board2048 &board) {
    vector<vector<int>> vecOptions = getVectors(board); //get vector options next board
    vector<int> scoreOptions = board.getTempScore(); //get score options next board

    //if no options available, return current board. The game is already over.
    if (vecOptions.empty()){
        return board.getBoard();
    }

    vector<int> boardChoice; //initialize boardChoice

    //for every next board option, get the boardValue
    for (int i = 0;i<vecOptions.size();i++) {
        boardChoice.push_back(boardValueFun(vecOptions[i],scoreOptions[i]));
        //Also get the value of the best next board option
        int bestNextStep = nextStep(vecOptions[i]);
        double weighFactorNS = 0.7; //weight factor next step
        //add influence best next step to board choice
        boardChoice[i] += (int)(weighFactorNS*bestNextStep);
    }

    //get the index of the maximum boardChoice value
    int index = distance(boardChoice.begin(),max_element(boardChoice.begin(), boardChoice.end()));
    //use index to get score option
    int score = scoreOptions[index];
    //add score to total score of the board
    board.addScore(score);
    //return the chosen next board
    return vecOptions[index];
}

//---------------------getInput-----------------------------------
//GETINPUT in HumanPlayer asks for a direction and checks if it is a correct input, if true, it updates scores and
//returns the next board.
/* Input:
 *      - Board2048 &board: the current board of which the next move is given
 * Output:
 *      - vector<int> vecOptions[index]: the vector of the chosen next board
 */
vector<int> HumanPlayer::getInput(Board2048 &board){
    bool goodInput = false; //initialize goodInput to false
    string dir; //initialize input direction
    int index = 0; //initialize direction index
    vector<vector<int>> vecOptions = getVectors(board); //initialize board options
    vector<char> dirOptions = getDirections(); //initialize direction options
    vector<int> scoreOptions = board.getTempScore(); //initialize score options

    //if no options available, return current board. The game is already over.
    if (vecOptions.empty()){
        return board.getBoard();
    }

    //ask for direction, check if valid direction, else give error message and wait for new input
    cout << "Input your wanted direction! (w,a,s,d)" << endl;
    while (!goodInput) {
        getline(cin,dir); //get input line, use the first character dir[0]
        if (dir[0] != 'w' && dir[0] != 'a' && dir[0] != 's' && dir[0] != 'd') {
            cout << "This is not a correct input! Input new direction (w,a,s,d)" << endl;
        } else if (find(dirOptions.begin(), dirOptions.end(), dir[0]) != dirOptions.end()){
            //find the direction option equal to the input direction
            index = distance(dirOptions.begin(), find(dirOptions.begin(), dirOptions.end(), dir[0]));
            //set the chosen score option and add it to the total score of the board
            int score = scoreOptions[index];
            board.addScore(score);
            //set goodInput to true to get out of the while loop
            goodInput = true;
        } else {
            cout << "This direction does not move any number! Input new direction (w,a,s,d)" << endl;
        }
    }
    //return the chosen direction vector
    return vecOptions[index];
}