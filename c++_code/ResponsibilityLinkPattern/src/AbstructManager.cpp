#include "AbstructManager.h"
void AbstructManager::setNextManager(AbstructManager *manager)
{
    m_next = manager;
}