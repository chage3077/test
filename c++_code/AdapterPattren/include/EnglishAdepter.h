#ifndef ENGLISHADEPTER_H
#define ENGLISHADEPTER_H
#include"AbstructAdepter.h"
class EnglishAdepter:public AbstructAdepter
{
private:
    /* data */
public:
    using AbstructAdepter::AbstructAdepter; // 继承父类定义的所有构造函数
    ~EnglishAdepter(){};
    void translateToChinese();
    void transloateToForeign();
};
#endif