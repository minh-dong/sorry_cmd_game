#include <iostream>
#include "ExODU.h"
#include "boardData.h"

void boardData::createBoard()
{
    for(int i = 0; i < 40; i++)
        board[i] = '*';

    for(int i = 0; i < 40; i++)
        tempBoard[i] = "***";

    for(int i = 0; i < 4; i++)
    {
        playerEnd[i] = '0';
        greenEnd[i] = '0';
        blueEnd[i] = '0';
        redEnd[i] = '0';
    }
}

void boardData::display(playerData& boardPlayer, int boardRoll) const
{
    string leftMargin = "     "; // 5 spaces
    string leftMarginGame = "        "; // 7 spaces
    string space = "   "; // 3 spaces
    char slash = 92; // "\"

    //Row 1 (player Human and Green)
    cout << leftMargin << boardPlayer.getname(0) << "                            " << boardPlayer.getname(1);
    cout << endl;

    //Row 2 (Pegs from human and green)
    cout << leftMargin << boardPlayer.getpeg(0) << "                                      " << boardPlayer.getpeg(1);
    cout << endl;

    // Row 3 (asterisk for the game 0 to 10)
    cout << leftMarginGame << board[0] << space << board[1] << space << board[2] << space << board[3] << space <<
                            board[4] << space << board[5] << space << board[6] << space << board[7] << space <<
                            board[8] << space << board[9] << space << board[10];
    cout << endl << endl;

    // Row 4 (asterisk for the game 39 and 11, end Stuff 0)
    cout << leftMarginGame << board[39] << space << playerEnd[0] << "                               " << greenEnd[0] << space << board[11];
    cout << endl << endl;

    // Row 5 (asterks for the game 38 and 12, end stuff 1)
    cout << leftMarginGame << board[38] << " " << space << space << playerEnd[1] << "                       " << greenEnd[1] << space << space << " " << board[12];
    cout << endl << endl;

    // Row 6 (asterks for the game 37 and 13, end stuff 2)
    cout << leftMarginGame  << board[37] << "  " << space << space << space << playerEnd[2] << "               " << greenEnd[2] << space << space << space << "  " << board[13];
    cout << endl << endl;

    // Row 7 (asterks for the game 36 and 14, end stuff 3)
    cout << leftMarginGame << board[36] << space << space << space << space << space << playerEnd[3] << "  /-"<< slash << "  " << greenEnd[3] << space << space << space << space << space << board[14];
    cout << endl << "                          :   : " << endl;

    // Row 8 (asterks for the game 35 and 15, dice)
    cout << leftMarginGame << board[35] << "                 : " << boardRoll << " :                 " << board[15];
    cout << endl << "                          :   : " << endl;

    // Row 9 (asterks for the game 34 and 16, end stuff 3)
    cout << leftMarginGame << board[34] << space << space << space << space << space << blueEnd[3] << "  " << slash << "-/" << "  " << redEnd[3] << space << space << space << space << space << board[16];
    cout << endl << endl;

    // Row 10 (asterks for the game 33 and 17, end stuff 2)
    cout << leftMarginGame  << board[33] << "  " << space << space << space << blueEnd[2] << "               " << redEnd[2] << space << space << space << "  " << board[17];
    cout << endl << endl;

    // Row 11 (asterks for the game 32 and 18, end stuff 1)
    cout << leftMarginGame << board[32] << " " << space << space << blueEnd[1] << "                       " << redEnd[1] << space << space << " " << board[18];
    cout << endl << endl;

    // Row 12 (asterks for the game 31 and 19, end stuff 0)
    cout << leftMarginGame << board[31] << space << blueEnd[0] << "                               " << redEnd[0] << space << board[19];
    cout << endl << endl;

    // Row 13 (asterks for the game 30 to 20)
    cout << leftMarginGame << board[30] << space << board[29] << space << board[28] << space << board[27] << space <<
                            board[26] << space << board[25] << space << board[24] << space << board[23] << space <<
                            board[22] << space << board[21] << space << board[20];
    cout << endl;

    // Row 14 (Blue and red names)
    cout << leftMargin << boardPlayer.getname(3) << "                 " << boardPlayer.getname(2);
    cout << endl;

    // Row 15 (blue and red pegs)
    cout << leftMargin << boardPlayer.getpeg(3) << "                                      " << boardPlayer.getpeg(2);
    cout << endl;
}
