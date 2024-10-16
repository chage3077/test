#ifndef SHIP_H
#define SHIP_H
#include <iostream>
#include <string>
#include "AbstructTeam.h"
using namespace std;
// 定义抽象部分——船
class AbstructShip
{
private:
    /* data */
protected:
    AbstructTeam *m_abstructTeam; // 用于记录当前的船是哪个团队在使用
public:
    AbstructShip(AbstructTeam *abstructTeam) : m_abstructTeam(abstructTeam) {};
    void show();                  // 简单输出一些团队的信息
    virtual string getName() = 0; // 获取船的名字
    virtual void feature() = 0;   // 输出船的特征

    virtual ~AbstructShip(){};
};
#endif