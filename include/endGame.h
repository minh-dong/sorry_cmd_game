#ifndef ENDGAME_H
#define ENDGAME_H
#include "boardData.h"

/*
    - The game will be checked every time after all players made their moves.
*/

class endGame
{
    private:
        struct endInfo
        {
            int determineWinner;
            int pegsCount[4];
        };
    public:
        void checkHomeSpace(boardData&, int &flag);
};

#endif // ENDGAME_H
