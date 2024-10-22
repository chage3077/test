#include "AbstructTeam.h"

string AbstructTeam::getName()
{
    return m_name;
}

void AbstructTeam::setParentNode(AbstructTeam *node)
{
    m_parent=node;
}

AbstructTeam::AbstructTeam(string name)
{
    m_name=name;
}

bool AbstructTeam::hasChild()
{
    return false;
}

AbstructTeam *AbstructTeam::getParentNode()
{
    return m_parent;
}

