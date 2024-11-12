#ifndef ANGEL_H
#define ANGEL_H
#include "AbstructRobot.h"
class Angel : public AbstructRobot
{
private:
    /* data */
public:
    // 武器
    void weapon() override;
    // 外观
    void appearance() override;
    // 战斗能力
    void fightAbility() override;
    // 名字
    string getName() override;
    // 自愈能力
    void canHealing() override;
    // 是否能飞
    bool canFly() override;
    // 是否可以自动控制
    bool isAuto() override;
};
#endif