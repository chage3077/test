#include "NewsAgency.h"

void NewsAgency::attach(Observer *observer)
{
    m_observer.push_back(observer);
}

void NewsAgency::detach(Observer *Observer)
{
    m_observer.remove(Observer);
}
