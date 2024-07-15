#ifndef EXODU_H
#define EXODU_H

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "playerData.h"
#include "boardData.h"

using namespace std;

/*
    - The main functionality of the ENTIRE program including roll (dice) and flag (determine the winner)
    - Human play function lives in this header file to keep things organized and separated fro AI functions...
    Also to keep this .cpp file organized and clean
*/


class ExODU
{
    private:
        int roll = 1;   // the dice for the game
        int flag = 0;   // determine the winner - checked by endGame.h
    public:
        // Functions
        void playGame();    // to play the game
        int generateRoll(); // to roll the dice
        void humanPlay(playerData&, boardData&);   // all related functions and stuff will be here based on the human
        void checkPegs(playerData&, boardData&, string, int, int);    // to be finished: will determine to move team peg to tempBoard or kill the enemy peg
        void moveHidden(playerData&, boardData&, int&, int&, string, int, int, int);  // to be created: any pegs hidden will be moved based on player's choice
};

// generate the roll from 1 to 6
inline
int ExODU::generateRoll()
{
    srand( time(NULL) );

    roll = rand()%6+1;

    return roll;
}


#endif // EXODU_H
