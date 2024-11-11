#ifndef XIAOHONG_H
#define XIAOJONG_H
#include"Observer.h"
class XiaoHong:public Observer
{
private:
    /* data */
public:
    using Observer::Observer;
    void update(string msg) override;
};
#endif