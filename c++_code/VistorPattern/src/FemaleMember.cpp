#include "FemaleMember.h"
void FemaleMember::accept(AbstructAction *action)
{
    action->femaleDoing(this);
}
