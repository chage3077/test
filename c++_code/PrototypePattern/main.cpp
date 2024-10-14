#include "Child1.h"
#include "Child2.h"
int main()
{
    Father *obj = new Child1;
    Father *child1 = obj->getClone();
    cout << "I am " + obj->getIndentity() << endl;
    obj = new Child2;
    Father *child2 = obj->getClone();
    cout << "I am " + obj->getIndentity() << endl;
    delete obj;
    delete child1;
    delete child2;
    return 0;
}