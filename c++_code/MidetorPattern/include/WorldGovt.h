#ifndef WORLDGOVT
#define WORLDGOVT
#include"Mediator.h"
// 中介者子类——世界组织
class WorldGovt:public Mediator
{
private:
    /* data */
public:
    void declare(string msg,Country* country,string name)override;
};
#endif