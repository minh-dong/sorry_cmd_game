#ifndef PLAYERDATA_H
#define PLAYERDATA_H
#include <string>
using namespace std;

/*
    All player information will reside here.
*/

class playerData
{
    private:
        string name[4]; // hold the player names
        string pegs[4]; // hold all the pegs for each player
        int pegsOut[4]; // determine how many pegs are out on the field

    public:
        // Creating the player functions
        void createName();
        void createPegs();
        void createPegsOut();


        // get functions
        string getname(int);
        string getpeg(int);
        int getpegsOut(int);

        // set functions
        string setpeg(int, string);
        int setpegsOut(int, int);
};

inline
string playerData::getname(int index)
{
    return name[index];
}

inline
string playerData::getpeg(int index)
{
    return pegs[index];
}

inline
string playerData::setpeg(int index, string i)
{
    pegs[index] = i;
    return pegs[index];
}

inline
int playerData::getpegsOut(int index)
{
    return pegsOut[index];
}

inline
int playerData::setpegsOut(int index, int i)
{
    pegsOut[index] = i;
    return pegsOut[index];
}

#endif // PLAYERDATA_H
