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

char userInput(){
    char direction = 'O';
    char c;
    cout<<"Input your wanted direction! (w,a,s,d)"<<endl;
    while (direction == 'O'){
        cin>>c;
        if (c != 'w' && c != 'a' && c != 's' && c != 'd') {
            cout<<"This is not a correct input!"<<endl;
        } else {
            direction = c;
        }
    }
    return direction;
}

int main ( )
{
    Board board = createBoard();

}