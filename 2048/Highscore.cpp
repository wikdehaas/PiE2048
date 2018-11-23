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

//-------------------------Highscore--------------------------
//HIGHSCORE is the constructor Highscore. It sets the maximum name length when the constructor is called
/* Input:
 *      - int length: the given maximum name length
 * Output:
 *      - none
 */
Highscore::Highscore(int length) {
    setMaxNameLength(length);
}

//-------------------------readHighscoreList-----------------------
//READHIGHSCORELIST reads the current highscore list en returns it
/* Input:
 *      - none
 * Output:
 *      - vector<highscore> currHsList: the sorted vector of highscores
 */
vector<Highscore::highscore> Highscore::readHighscoreList() {
    vector<highscore> currHsList;
    string temp_name;
    int temp_score;

    //if the file with highscores exist, read the highscores and put it in currHsList
    ifstream inputFile;
    inputFile.open("highscore_list.txt");
    if (inputFile.is_open()) {
        while (inputFile >> temp_name >> temp_score) {
            currHsList.push_back({temp_name, temp_score});
        }
    } else {
        cerr << "Error: couldn't open/find highscores_list.txt" << endl;
        exit(1);
    }
    inputFile.close();
    //put the current highscore list in descending order and return it
    sort(currHsList.begin(), currHsList.end());
    reverse(currHsList.begin(), currHsList.end());
    return currHsList;
}

//--------------------------addHighscore-------------------------------
//ADDHIGHSCORE appends a new score to the existing text file highscore_list
/* Input:
 *      - string name: name of player
 *      - int score: score of game
 * Output:
 *      - none
 */
void Highscore::addHighscore(string name, int score) {
    ofstream outputFile;
    outputFile.open("highscore_list.txt", ios_base::app);
    outputFile << name << "    " << score << endl;
    outputFile.close();
}

//----------------------------viewHighscore-----------------------
//VIEWHIGHSCORE asks if the client wants to see the highscores, when y, shows the highscores
/* Input:
 *      - none
 * Output:
 *      - none
 */

void Highscore::viewHighscore(){
    bool goodInput = false; //set goodInput to false to go into while loop
    string inputView; //the input of the client (y..,n.. or invalid string)
    int maxHighscores = 10; //the maximum amount of highscore that are shown

    cout << "Show top " << maxHighscores << " scores? y/n" << endl;
    while (!goodInput) {
        //get line from client, check the first character. If y, set the Highscore list and output it to screen
        getline(cin,inputView);
        if (inputView[0] == 'y') {
            goodInput = true; //get out of while loop
            setHSList();
            for (int i = 0; (i < maxHighscores && i < hsList.size()); i++) {
                cout << left << setw(maxNameLength) << hsList[i].hsName << "   " << hsList[i].hsValue << endl;
            }

        } else {
            //if not 'n', tell user wrong input. Does loop again
            if (inputView[0] != 'n') {
                cout << "Invalid input. Enter y or n" << endl;
            }
            else {
                goodInput = true; //go out of loop. No output is shown
            }
        }
    }
}

//----------------------setMaxNameLength-----------------------------
//SETMAXNAMELENGTH sets the name length. It is called in the constructor
/* Input:
 *      - int length: given maximum name length
 * Output:
 *      - none
 */
void Highscore::setMaxNameLength(int length) {
    maxNameLength = length;
}

//----------------------setHSList------------------------------------
//SETHSLIST calls readHighscoreList and updates hsList accordingly
/* Input:
 *      - none
 * Output:
 *      - none
 */
void Highscore::setHSList() {
    hsList = readHighscoreList();
}

