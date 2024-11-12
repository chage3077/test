#include "HorrorAction.h"
#include "MaleMember.h"
#include "FemaleMember.h"
void HorrorAction::maleDoing(MaleMember *male)
{
    cout << "I am " << male->getName() << endl;
    thinking();
}

void HorrorAction::femaleDoing(FemaleMember *female)
{
    cout << "I am " << female->getName() << endl;
    help();
}

void HorrorAction::help()
{
    cout << "We should find help." << endl;
}

void HorrorAction::thinking()
{
    cout << "we should fight this guy together.I can't fight it." << endl;
}
