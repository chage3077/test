#ifndef XIAOMING_H
#define XIAOMING_H
#include"Observer.h"
class XiaoMing:public Observer
{
private:
    /* data */
public:
    using Observer::Observer;
    void update(string msg) override;
};
#endif