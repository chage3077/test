#ifndef XIAOFANG_H
#define XIAOFANG_H
#include"Observer.h"
class XiaoFang:public Observer
{
private:
    /* data */
public:
    using Observer::Observer;
    void update(string msg) override;
};
#endif