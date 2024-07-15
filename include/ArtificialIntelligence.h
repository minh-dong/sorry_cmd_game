#ifndef ARTIFICIALINTELLIGENCE_H
#define ARTIFICIALINTELLIGENCE_H
#include "playerData.h"
#include "boardData.h"

/*
    - This is where all artificial intelligence will be given to the three computers.
    - The reason why each computer has its own functions is based on the computer's perspective.
    - Based on the computer's perspective, the function will be slightly different depending where the computer
    is placed on the screen. This is to prevent from board array to go out of scope, and cause it to mess up with
    other arrays and/or crash the program.
*/

class ArtificialIntelligence
{
    private:
        // this struct is used to determine individual rolls
        // each AI will have their own specific roll - to prevent the same roll from happening when using rand()
        struct roll
        {
            int greenRoll;
            int redRoll;
            int blueRoll;
        };

    public:
        // AIs functions
        void greenPlay(playerData&, boardData&);    // green functionalities
        void redPlay(playerData&, boardData&);      // red functionalities
        void bluePlay(playerData&, boardData&);     // blue functionalities

        // Function for killing
        void AIcheck(playerData&, boardData&, int roll, int checkAhead, int player);
};

#endif // ARTIFICIALINTELLIGENCE_H
