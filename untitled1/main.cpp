#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std ;

const int SIZE = 4;

int high_score = 0;

void plot_matrix(vector<int> matrix){
    for (int i = 0; i <SIZE; i++){
        for (int j = 0; j <SIZE; j++) {
            cout << matrix[j+i*SIZE] <<' ';
        }
        cout<< endl;
    }
    cout<<endl;
}

template <class BidirectionalIterator>
void reverse (BidirectionalIterator first, BidirectionalIterator last)
{
    while ((first!=last)&&(first!=--last)) {
        std::iter_swap (first,last);
        ++first;
    }
}

bool isZero (int i)
{
    return i == 0;
}

vector<int> shiftVector(vector<int> temp_vec) {
    vector<int>::iterator newIter = std::remove_if(temp_vec.begin(), temp_vec.end(), isZero);
    temp_vec.resize(newIter - temp_vec.begin());

    for (unsigned j = 0; j < (temp_vec.size() - 1); j++) {
        if (temp_vec[j] == temp_vec[j + 1]) {
            temp_vec[j] = temp_vec[j] * 2;
            temp_vec[j + 1] = 0;
            high_score = high_score + temp_vec[j] * 2;
        }
    }

    newIter = std::remove_if(temp_vec.begin(), temp_vec.end(), isZero);
    temp_vec.resize(newIter - temp_vec.begin());

    temp_vec.resize(4);
    return temp_vec;
}


vector<int> updateMatrix(vector<int> matrix, char direction ){
    switch(direction) {
        case 'w':
            for (int i = 0; i < SIZE; i++) {
                vector<int> temp_vec(SIZE);
                for (unsigned j = 0; j < temp_vec.size(); j++) {
                    temp_vec.at(j) = matrix[i + j * SIZE];
                }
                temp_vec = shiftVector(temp_vec);
                for (int j = 0; j != temp_vec.size(); ++j) {
                    matrix[i + j * SIZE] = temp_vec[j];
                }
            }
            return matrix;
        case 'a':
            for (int i = 0; i < SIZE; i++) {
                vector<int> temp_vec(SIZE);
                for (unsigned j = 0; j < temp_vec.size(); j++) {
                    temp_vec.at(j) = matrix[i * SIZE + j];
                }
                temp_vec = shiftVector(temp_vec);
                for (int j = 0; j != temp_vec.size(); ++j) {
                    matrix[i * SIZE + j] = temp_vec[j];
                }
            }
            return matrix;
        case 's':
            for (int i = 0; i < SIZE; i++) {

                vector<int> temp_vec(SIZE);
                for (unsigned j = 0; j < temp_vec.size(); j++) {
                    temp_vec.at(j) = matrix[i + j * SIZE];
                }
                std::reverse(temp_vec.begin(), temp_vec.end());
                temp_vec = shiftVector(temp_vec);
                std::reverse(temp_vec.begin(), temp_vec.end());

                for (int j = 0; j != temp_vec.size(); ++j) {
                    matrix[i + j * SIZE] = temp_vec[j];
                }

            }
            return matrix;
        case 'd':
            for (int i = 0; i < SIZE; i++) {
                vector<int> temp_vec(SIZE);
                for (unsigned j = 0; j < temp_vec.size(); j++) {
                    temp_vec.at(j) = matrix[i * SIZE + j];
                }

                std::reverse(temp_vec.begin(), temp_vec.end());
                temp_vec = shiftVector(temp_vec);
                std::reverse(temp_vec.begin(), temp_vec.end());

                for (int j = 0; j != temp_vec.size(); ++j) {
                    matrix[i * SIZE + j] = temp_vec[j];
                }
            }
            return matrix;
        default:
            return matrix;

    }
}

void update(vector<int> matrix){
    string str("wasd");
    bool gameover = true;

    vector<int> matrix_left = updateMatrix(matrix, 'a');
    vector<int> matrix_right = updateMatrix(matrix, 'd');
    vector<int> matrix_up = updateMatrix(matrix, 'w');
    vector<int> matrix_down = updateMatrix(matrix, 's');

    if( matrix_left==matrix_right){
        if(matrix_up==matrix_down){
            if(matrix_left==matrix){
                gameover = true;
            }
        }
    }
}



class update{
    // --------------- variables -------------------------------------------

    char ALLDIR[5] = "wasd";
    vector<int> score;
    vector<char> valid_directions;
    vector< vector<int>> allMatrix;
    vector<int> temp_mat;
    int counter;


    // --------------- Function which inverts vector -------------------------------------------

    template <class BidirectionalIterator>
    void reverse (BidirectionalIterator first, BidirectionalIterator last)
    {
        while ((first!=last)&&(first!=--last)) {
            std::iter_swap (first,last);
            ++first;
        }
    }

    bool isZero (int i)
    {
        return i == 0;
    }


    // --------------- Function which shifts vector -------------------------------------------
    vector<int> shiftVector(vector<int> temp_vec) {
        vector<int>::iterator newIter = std::remove_if(temp_vec.begin(), temp_vec.end(), isZero);
        temp_vec.resize(newIter - temp_vec.begin());

        for (unsigned j = 0; j < (temp_vec.size() - 1); j++) {
            if (temp_vec[j] == temp_vec[j + 1]) {
                temp_vec[j] = temp_vec[j] * 2;
                temp_vec[j + 1] = 0;
                //high_score = high_score + temp_vec[j] * 2;
            }
        }

        newIter = std::remove_if(temp_vec.begin(), temp_vec.end(), isZero);
        temp_vec.resize(newIter - temp_vec.begin());

        temp_vec.resize(4);
        return temp_vec;
    }

    // --------------- Function which updates matrix -------------------------------------------

    vector<int> updateMatrix(vector<int> matrix, char direction ){
        switch(direction) {
            case 'w':
                for (int i = 0; i < SIZE; i++) {
                    vector<int> temp_vec(SIZE);
                    for (unsigned j = 0; j < temp_vec.size(); j++) {
                        temp_vec.at(j) = matrix[i + j * SIZE];
                    }
                    temp_vec = shiftVector(temp_vec);
                    for (int j = 0; j != temp_vec.size(); ++j) {
                        matrix[i + j * SIZE] = temp_vec[j];
                    }
                }
                return matrix;
            case 'a':
                for (int i = 0; i < SIZE; i++) {
                    vector<int> temp_vec(SIZE);
                    for (unsigned j = 0; j < temp_vec.size(); j++) {
                        temp_vec.at(j) = matrix[i * SIZE + j];
                    }
                    temp_vec = shiftVector(temp_vec);
                    for (int j = 0; j != temp_vec.size(); ++j) {
                        matrix[i * SIZE + j] = temp_vec[j];
                    }
                }
                return matrix;
            case 's':
                for (int i = 0; i < SIZE; i++) {

                    vector<int> temp_vec(SIZE);
                    for (unsigned j = 0; j < temp_vec.size(); j++) {
                        temp_vec.at(j) = matrix[i + j * SIZE];
                    }
                    std::reverse(temp_vec.begin(), temp_vec.end());
                    temp_vec = shiftVector(temp_vec);
                    std::reverse(temp_vec.begin(), temp_vec.end());

                    for (int j = 0; j != temp_vec.size(); ++j) {
                        matrix[i + j * SIZE] = temp_vec[j];
                    }

                }
                return matrix;
            case 'd':
                for (int i = 0; i < SIZE; i++) {
                    vector<int> temp_vec(SIZE);
                    for (unsigned j = 0; j < temp_vec.size(); j++) {
                        temp_vec.at(j) = matrix[i * SIZE + j];
                    }

                    std::reverse(temp_vec.begin(), temp_vec.end());
                    temp_vec = shiftVector(temp_vec);
                    std::reverse(temp_vec.begin(), temp_vec.end());

                    for (int j = 0; j != temp_vec.size(); ++j) {
                        matrix[i * SIZE + j] = temp_vec[j];
                    }
                }
                return matrix;
            default:
                return matrix;

        }
    }

public:

    vector<char> getDirections(){
        return valid_directions;
    }

    void getVectors(vector<int> matrix){
        valid_directions.clear();
        allMatrix.clear();
        counter = 0;

        //matrix = get board
        for (int i = 0; i < SIZE; i++){
            temp_mat = updateMatrix( matrix, ALLDIR[i] );
            if (temp_mat == matrix){
            }else{
                valid_directions[counter]=ALLDIR[i];
                for(i=0;i<temp_mat.size();i++) {
                    allMatrix[counter][i]=temp_mat[i];
                }
            }

        }

    }

    void getpoints(){

    }
};




int main() {
    vector<int> matrix={0,2,2,84,2,2,0,2,2,2,0,0,2,0,2,0};
    plot_matrix(matrix);

    vector<int> matrix_test;
    matrix_test = updateMatrix(matrix, 'w' );
    plot_matrix(matrix_test);

    matrix_test = updateMatrix(matrix, 'a' );
    plot_matrix(matrix_test);

    matrix_test = updateMatrix(matrix, 's' );
    plot_matrix(matrix_test);

    matrix_test= updateMatrix(matrix, 'd' );
    plot_matrix(matrix_test);

    return 0;
}