#ifndef AMERICANADEPTER_H
#define AMERICANADEPTER_H
#include"AbstructAdepter.h"
class AmericanAdepter:public AbstructAdepter
{
private:
    /* data */
public:
    using AbstructAdepter::AbstructAdepter; // 继承父类定义的所有构造函数
    ~AmericanAdepter(){};
    void translateToChinese();
    void transloateToForeign();
};
#endif