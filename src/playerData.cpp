#include <iostream>
#include "playerData.h"

using namespace std;

void playerData::createName()
{
    string getName;

    cout << "Enter your name" << endl;
    getline(cin, getName);

    name[0] = getName;
    name[1] = "Green Corner (g)";
    name[3] = "Blue Corner (b)";
    name[2] = "Red Corner (r)";
}

void playerData::createPegs()
{
    pegs[0] = "1234";
    pegs[1] = "gggg";
    pegs[3] = "bbbb";
    pegs[2] = "rrrr";
}

void playerData::createPegsOut()
{
    for(int i = 0; i < 4; i++)
        pegsOut[i] = 0;
}

