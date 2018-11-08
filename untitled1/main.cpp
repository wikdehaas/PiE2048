#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std ;

int SIZE = 4;

void plot_matrix(vector<int> matrix){
    for (int i = 0; i <SIZE; i++){
        for (int j = 0; j <SIZE; j++) {
            cout << matrix[j+i*SIZE] <<' ';
        }
        cout<< endl;
    }
    cout<<endl;
}

// --------------------------------------------------------------------
// --------------- Class ----------------------------------------------
// --------------------------------------------------------------------
class update{
    // --------------- variables -------------------------------------------

    char ALLDIR[5] = "wasd";
    vector<int> score_vec;
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
    vector<int> shiftVector(vector<int> tempVec, int& score) {
        tempVec = removeZeroes(tempVec);
        for (unsigned j = 0; j < (tempVec.size() - 1); j++) {
            if (tempVec[j] == tempVec[j + 1]) {
                tempVec[j] = tempVec[j] * 2;
                tempVec[j + 1] = 0;
                score = score + tempVec[j];
            }
        }
        tempVec = removeZeroes(tempVec);
        tempVec.resize(4);
        return tempVec;
    }

    // --------------- Function which updates matrix -------------------------------------------
    vector<int> updateMatrix(vector<int> matrix, char direction, int& score ){
        switch(direction) {
            case 'w':
                for (int i = 0; i < SIZE; i++) {
                    vector<int> tempVec(SIZE);
                    for (unsigned j = 0; j < tempVec.size(); j++) {
                        tempVec.at(j) = matrix[i + j * SIZE];
                    }
                    tempVec = shiftVector(tempVec, score);
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
                    tempVec = shiftVector(tempVec, score);
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
                    tempVec = shiftVector(tempVec,score);
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
                    tempVec = shiftVector(tempVec,score);
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

public:

    vector<char> getDirections(){
        return valid_directions;
    }

    void getVectors(vector<int> matrix, int score){
        int score_temp;
        valid_directions.clear();
        allMatrix.clear();
        score_vec.clear();
        counter = 0;

        //matrix = get board
        //get score
        for (int i = 0; i < SIZE; i++){
            score_temp=score;
            temp_mat = updateMatrix( matrix, ALLDIR[i], score_temp);
            if (temp_mat == matrix){

            }else{
                valid_directions.push_back(ALLDIR[i]);
                allMatrix.push_back(temp_mat);
                score_vec.push_back(score_temp);
                counter++;
            }
        }
    }

    vector<int> getpoints(){
        return score_vec;
    }
};

int main() {
    vector<int> matrix={2,4,8,16,2,4,8,16,2,4,8,16,2,4,8,16};
    plot_matrix(matrix);

    update vector1;
    vector1.getVectors(matrix, 12);

    vector<int> test = vector1.getpoints();
    vector<char> test2 = vector1.getDirections();

    for(auto &i: test2)
        std::cout << i << endl;

    for(auto &i: test)
        std::cout << i << endl;

    return 0;
}