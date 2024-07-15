#ifndef BOARDDATA_H
#define BOARDDATA_H
#include "playerData.h"

using namespace std;

/*
    - All board functionalities will reside here, such as displaying information,
    holding pegs if on the same spot, etc.. etc..
*/

class boardData
{
    private:
        // board Stuff
        string board[40]; // Entire game display
        string tempBoard[40]; // only used if there are more than one peg on the board

        // End Game
        string playerEnd[4];    // used for human
        string greenEnd[4];     // AI #1
        string blueEnd[4];      // AI #2
        string redEnd[4];       // AI #3
    public:
        // Functions
        void createBoard(); // Will initialize the entire starting board
        void display(playerData&, int boardRoll) const; // Used to display the board every time

        // Get function for board
        string getBoard(int);
        string gettempBoard(int);

        // Get functions for all home positions
        string getplayerEnd(int);
        string getgreenEnd(int);
        string getblueEnd(int);
        string getredEnd(int);

        // Set function for board
        string setBoard(int, string);
        string settempBoard(int, string);

        // Set function for all home positions
        string setplayerEnd(int, string);
        string setgreenEnd(int, string);
        string setblueEnd(int, string);
        string setredEnd(int, string);

};

inline
string boardData::getBoard(int index)
{
    return board[index];
}

inline
string boardData::getplayerEnd(int index)
{
    return playerEnd[index];
}

inline
string boardData::getgreenEnd(int index)
{
    return greenEnd[index];
}

inline
string boardData::getblueEnd(int index)
{
    return blueEnd[index];
}

inline
string boardData::getredEnd(int index)
{
    return redEnd[index];
}

inline
string boardData::setBoard(int index, string i)
{
    board[index] = i;
    return board[index];
}

inline
string boardData::setplayerEnd(int index, string i)
{
    playerEnd[index] = i;
    return playerEnd[index];
}

inline
string boardData::setgreenEnd(int index, string i)
{
    greenEnd[index] = i;
    return greenEnd[index];
}

inline
string boardData::setblueEnd(int index, string i)
{
    blueEnd[index] = i;
    return blueEnd[index];
}

inline
string boardData::setredEnd(int index, string i)
{
    redEnd[index] = i;
    return redEnd[index];
}

inline
string boardData::gettempBoard(int index)
{
    return tempBoard[index];
}

inline
string boardData::settempBoard(int index, string i)
{
    tempBoard[index] = i;
    return tempBoard[index];
}

#endif // BOARDDATA_H
