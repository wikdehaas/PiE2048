#include <iostream>
#include <valarray>
#include <vector>

using namespace std;

const int SIZE_BOARD = 4;

class Board{
private:
    vector<int> board;
public:
    void setValue(int index, int value){
        board[index] = value;
    }
    int getValue(int index){
        return board[index];
    }
};

Board createBoard(){
    Board board;
    vector<int> boardValues(SIZE_BOARD^2,0);
    for (int i = 0; i < boardValues.size(); i++){
        board.setValue(i,boardValues[i]);
    }
    return board;
}

class Update {
public:
    vector<char> getDirections();
    vector<vector<int>> getVectors();
};

class Player {
public:
    virtual vector<int> getInput();
};

class ComputerPlayer : public Player {
private:
    vector<int> getInput() {
        vector<int> direction = {4,3,6};
        return direction;
    }
};

class HumanPlayer : public Player, Update {
private:
    vector<int> getInput() {
        vector<int> direction = {1,2,3};
        bool goodInput = false;
//        vector<char> dirOptions = getDirections();
//        vector<vector<int>> vecOptions = getVectors();
        vector<char> dirOptions = {'a','s'};
        vector<vector<int>> vecOptions(2,vector<int>(3,2));
        vecOptions[0][0] = 1;
        vecOptions[0][1] = 2;
        vecOptions[0][2] = 3;
        vecOptions[1][0] = 4;
        vecOptions[1][1] = 5;
        vecOptions[1][2] = 6;
        char c;
        cout << "Input your wanted direction! (w,a,s,d)" << endl;
        while (!goodInput) {
            cin >> c;
            if (c != 'w' && c != 'a' && c != 's' && c != 'd') {
                cout << "This is not a correct input!" << endl;
            } else if (find(dirOptions.begin(), dirOptions.end(), c) != dirOptions.end()){
                int index = distance(dirOptions.begin(), find(dirOptions.begin(), dirOptions.end(), c));
                direction = vecOptions[index];
                goodInput = true;
            } else {
                cout << "This direction does not move any number" << endl;
                goodInput = true;
            }
        }
        return direction;
    }
};

int main ( )
{
//    Board board = createBoard();
    ComputerPlayer CP;
    HumanPlayer HP;
    Player* player = &CP;
    vector<int> a = player->getInput();
    for (auto i: a)
        cout << i << endl;
    player = &HP;
    a = player->getInput();
    for (auto i: a)
        cout << i << endl;
}