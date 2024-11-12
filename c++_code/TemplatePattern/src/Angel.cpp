#include "Angel.h"

void Angel::weapon()
{
    cout << "Laser laser and Greatsword." << endl;
}

void Angel::appearance()
{
    cout << "beautiful." << endl;
}

void Angel::fightAbility()
{
    cout << "Using Laser laser and can fly." << endl;
}

string Angel::getName()
{
    return "Angel";
}

void Angel::canHealing()
{
    cout << "Can quickly healing." << endl;
}

bool Angel::canFly()
{
    return true;
}

bool Angel::isAuto()
{
    return true;
}
