#include "HaninkShip.h"

string HaninkShip::getName()
{
    return "Hanink ship";
}

void HaninkShip::feature()
{
    cout << getName() << ": has a big ship body and has many pirates." << endl;
}
