#ifndef PACIFIST_H
#define PACIFIST_H
#include "AbstructRobot.h"
class Pacifist : public AbstructRobot
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
};
#endif