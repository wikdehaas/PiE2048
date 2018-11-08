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
class Player {
public:
    virtual char getInput();
};

class ComputerPlayer : public Player {
public:
    char getInput() {
        char direction = 'O';
        return direction;
    }
};

class HumanPlayer : public Player {
public:
    char getInput() {
        char direction = 'O';
        char c;
        cout << "Input your wanted direction! (w,a,s,d)" << endl;
        while (direction == 'O') {
            cin >> c;
            if (c != 'w' && c != 'a' && c != 's' && c != 'd') {
                cout << "This is not a correct input!" << endl;
            } else {
                direction = c;
            }
        }
        return direction;
    }
};

int main ( )
{
    Board board = createBoard();
    ComputerPlayer CP;
    HumanPlayer HP;
    Player* player = &CP;
    char a = player->getInput();
    cout<< a<<endl;
    player = &HP;
    a = player->getInput();
    cout<< a << endl;


}