#include "MaleMember.h"
void MaleMember::accept(AbstructAction *action)
{
    action->maleDoing(this);
}
