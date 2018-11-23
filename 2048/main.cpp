/*C++11
 * Name: 2048
 * Authors: Wik de Haas, Emiel Haven, Maxim Peters
 * Date: Fall 2018
 * Course: Programming in Engineering, University of Twente
 *
 *  Usage:
 *          - Run this file
 *          - Follow the commands in the console
 *          - Enjoy!
 *
 * Synopsis: This program executes the game 2048. You can either play yourself or let the computer play. The goal is to
 *           combine tiles until you have a tile with value 2048 on the board. It is possible to continue after you
 *           achieved this until there are no valid moves left and then you are game over. A score is kept and added to
 *           the highscore upon game over.
 *           Tiles are combined by shifting the entire board in a certain direction. All neighbouring identical tiles
 *           will be added together and create a tile with the larger value.
 *           A move is valid if at least one tile moves.
 *
 * Subclass files:
 *          - Game2048.h, Game2048.cpp          (top level; governs and executes the game)
 *          - Board2048.h, Board2048.cpp        (governs and stores the board)
 *          - Update.h, Update.cpp              (checks all possible directions and updates board)
 *          - Player.h, Player.cpp              (governs player type and recieves human input or executes computer AI)
 *          - Highscore.h, Highscore.cpp        (governs the highscore and adds new entries)
 */

#include "Game2048.h"

using namespace std;

int main () {
    Game2048 game1; //Create Game2048 instance
    game1.runGame(); //Call runGame which executes the entire game

    return 0;
}