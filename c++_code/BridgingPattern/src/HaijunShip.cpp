#include "HaijunShip.h"

string HaijunShip::getName()
{
    return "The Haijun ship";
}

void HaijunShip::feature()
{
    cout << getName() << ": has many policemen and has many guns." << endl;
}
