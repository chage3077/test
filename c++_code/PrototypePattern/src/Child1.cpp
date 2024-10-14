#include "Child1.h"
Father *Child1::getClone()
{
    Father* p = new Child1();
    *p = *this;
    return p;
}

string Child1::getIndentity()
{
    return name;
}
