#ifndef HANJUNSHIP_H
#define HANJUNSHIP_H
#include "AbstructShip.h"
class HaijunShip : public AbstructShip
{
private:
    /* data */
public:
    using AbstructShip::AbstructShip; // 继承父类的带参构造函数
    string getName() override;        // 获取船的名字
    void feature() override;          // 输出船的特征
};
#endif