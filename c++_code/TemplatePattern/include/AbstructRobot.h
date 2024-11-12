#ifndef ABSTRUCTROBOT_H
#define ABSTRUCTROBOT_H
#include<iostream>
#include<string>
using namespace std;
class AbstructRobot
{
private:
    /* data */
public:
    // 武器
    virtual void weapon()=0;
    // 外观
    virtual void appearance()=0;
    // 战斗能力
    virtual void fightAbility()=0;
    // 名字
    virtual string getName()=0;
    // 自愈能力
    virtual void canHealing(){}
    // 是否能飞
    virtual bool canFly();
    // 是否可以自动控制
    virtual bool isAuto();
    // 得到当前机器人的属性
    virtual void getInfo();
};
#endif