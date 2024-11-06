#ifndef REVOLUAMY_H
#define REVOLUAMY_H
#include"Mediator.h"
class RevoluAmy:public Mediator
{
private:
    /* data */
public:
    void declare(string msg,Country* country,string name)override;
};
#endif