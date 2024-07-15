#include <iostream>
#include "ExODU.h"
#include "playerData.h"
#include "boardData.h"

using namespace std;

/// TASKS
/*
    *CHECK NOTES FOR SPECIFIC INFORMATION!

    1) Figure out how to "Press Enter to Continue"
    2) Finish creating the human play function
      // Create a new array so that the same team pegs can land on top of each other
        - Whatever landed on top of it first will be shown
        - The one under it will be moved to a new array
      // Finish with the rest of the functions
        - Create a new array called pegMove[16] - one for each peg for the four players
            + Example: Peg 1 will use pegMove[0] and will increment based on the given roll
            + When the pegMove for whatever peg reaches 40, start moving that peg in the home
    3) Work on the bots
      // There will be 3 functions
        - Based on the bot's location, they need certain functionalities to work properly
        - Use rand() to generate numbers in a certain range
    4) Create pegs killing
      // If peg is not a team member, kill it
        - Use if statements to determine if it does not equal to any team member pegs
        - Move the peg back to its respective owner
            + Make sure the peg moves in the correct spot
        - Display the message if the peg kills another peg
            + "You killed (peg)"
            + "Oh no! Your peg #number was killed by a enemy (color) peg. Press enter to continue.
    5) Revisit all functions to input necessary function whenever possible
*/

int main()
{
    // Class classification calling
    ExODU mygame;

    // Calling the function from ExODU to play the game
    mygame.playGame();

    return 0;
}
