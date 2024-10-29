#ifndef BOOMBODYFACTORY_H
#define BOOMBODYFACTORY_H
#include "SharedBoomBody.h"
#include "UniqueBoomBody.h"
#include <map>

// 享元类工厂
class BoomBodyFactory
{
private:
    /* data */
    map<string, FlyWeightBody *> m_sharedDataMap;

public:
    FlyWeightBody *getSharedData(string name, string spirt); // 传入型号，寻找该享元内存
    ~BoomBodyFactory();
};
#endif