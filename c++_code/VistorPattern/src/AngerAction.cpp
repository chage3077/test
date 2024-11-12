#include "AngerAction.h"
#include "MaleMember.h"
#include "FemaleMember.h"
void AngerAction::maleDoing(MaleMember *male)
{
    cout << "I am " << male->getName() << endl;
    fight();
}

void AngerAction::femaleDoing(FemaleMember *female)
{
    cout << "I am " << female->getName() << endl;
    warn();
}

void AngerAction::fight()
{
    cout << "I must fight long day until this guy death!!" << endl;
}

void AngerAction::warn()
{
    cout << "Everbody please runs quickly! Don't touch me!" << endl;
}
