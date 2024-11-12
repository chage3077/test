#include "AbstructRobot.h"

bool AbstructRobot::canFly()
{
    return false;
}

bool AbstructRobot::isAuto()
{
    return false;
}

void AbstructRobot::getInfo()
{
    cout << "The Robot " << getName() << " these abilities....." << endl;
    if (canFly())
        cout << "Can Fly." << endl;
    else
        cout << "Can not fly." << endl;
    if (isAuto())
        cout << "Can auto drive." << endl;
    else
        cout << "Can not auto drive." << endl;
    weapon();
    appearance();
    fightAbility();
    canHealing();
}
