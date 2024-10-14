#ifndef ABSTRUCTADEPTER_H
#define ABSTRUCTADEPTER_H
#include "Foreigner.h"
#include "Chinese.h"
class AbstructAdepter
{
private:
    /* data */
protected: // 子类适配器可以继承父类，存储对应的对象实例
    Foreigner *m_foreigner;
    Chinese *m_Chinese;

public:
    AbstructAdepter(Foreigner *foreigner) : m_foreigner(foreigner) {};
    virtual void translateToChinese() = 0;
    virtual void transloateToForeign() = 0;
    virtual ~AbstructAdepter(){};
};

#endif