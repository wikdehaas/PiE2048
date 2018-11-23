//
// Created by user on 22/11/2018.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Highscore.h"

using namespace std;

Highscore::Highscore(int length) {
    setMaxNameLength(length);
}

void Highscore::readHighscore() {
    hsList.clear();
    string temp_name;
    int temp_score;

    ifstream inputFile;
    inputFile.open("highscore_list.txt");
    if (inputFile.is_open()) {
        while (inputFile >> temp_name >> temp_score) {
            hsList.push_back({temp_name, temp_score});
        }
    } else {
        cerr << "error: couldn't open the highscores" << endl;

    }
    inputFile.close();
    sort(hsList.begin(), hsList.end());
    reverse(hsList.begin(), hsList.end());
    setHSList(hsList);
}

void Highscore::addHighscore(string name, int score) {
    ofstream outputFile;
    outputFile.open("highscore_list.txt", ios_base::app);
    outputFile << name << "    " << score << endl;
    outputFile.close();
}

ostream& operator<<(ostream& out, const Highscore::highscore& hs){
    out << hs.hsName << " " << hs.hsValue<<endl;
    return out;
}

void Highscore::viewHighscore(){
    bool goodInput = false;
    string inputView;

    cout << "Show top 10 scores? y/n" << endl;
    while (!goodInput) {
        getline(cin,inputView);
        if (inputView[0] == 'y') {
            goodInput = true;
            readHighscore();
            for (int i = 0; (i < 10 && i < hsList.size()); i++) {
                cout << left << setw(maxNameLength) << hsList[i].hsName << "   " << hsList[i].hsValue << endl;
            }

        } else {
            if (inputView[0] != 'n') {
                cout << "Invalid input. Enter y or n" << endl;
            }
            else {
                goodInput = true;
            }
        }
    }
}

void Highscore::setMaxNameLength(int length) {
    maxNameLength = length;
}

void Highscore::setHSList(vector<highscore> &hsl) {
    hsList = hsl;
}

