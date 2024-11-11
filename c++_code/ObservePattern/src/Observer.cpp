#include "Observer.h"

void Observer::unsubscribe()
{
    m_agency->detach(this);
}