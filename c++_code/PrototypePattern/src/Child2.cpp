#include "Child2.h"
Father *Child2::getClone()
{
    Father* p = new Child2();
    *p = *this;
    return p;
}

string Child2::getIndentity()
{
    return name;
}
