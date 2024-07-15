#include "endGame.h"
#include <iostream>

using namespace std;

void endGame::checkHomeSpace(boardData& endBoard, int &flag)
{
    endInfo myinfo; // struct for holding certain variables

    // TO end the game quickly to see if the function works
/*
    for(int i = 0; i < 4; i++)
        endBoard.setplayerEnd(i, "4");
*/

    // Initialize the 4 arrays with 0s
    for(int i = 0; i < 4; i++)
        myinfo.pegsCount[i] = 0;

    // To check if it actually sets the home array for player
    //endBoard.setplayerEnd(0, "1");

    // Check for human pegs
    for(int i = 0; i < 4; i++)
    {
        if(endBoard.getplayerEnd(i) != "0")
            myinfo.pegsCount[0]++;  // Increment if there is no 0 in a slot
    }

    // Check for blue pegs
    for(int i = 0; i < 4; i++)
    {
        if(endBoard.getblueEnd(i) != "0")
            myinfo.pegsCount[1]++;  // Increment if there is no 0 in a slot
    }

    // check for red pegs
    for(int i = 0; i < 4; i++)
    {
        if(endBoard.getredEnd(i) != "0")
            myinfo.pegsCount[2]++;  // Increment if there is no 0 in a slot
    }

    // check for green pegs
    for(int i = 0; i < 4; i++)
    {
        if(endBoard.getgreenEnd(i) != "0")
            myinfo.pegsCount[3]++;  // Increment if there is no 0 in a slot
    }

    // now check for the winner if there are four pegs in home
    for(int i = 0; i < 4; i++)
    {
        if(myinfo.pegsCount[i] == 4)
        {
            myinfo.determineWinner = i+1;   // determinedWinner will be saved based on who has four pegs in home
            flag = myinfo.determineWinner; // the flag will change depending on who won
        }
    }

}
