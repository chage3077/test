#ifndef CAOMAOTEAM_H
#define CAOMAOTEAM_H
#include "AbstructTeam.h"
class CaoMaoTeam : public AbstructTeam
{
private:
    /* data */
public:
    using AbstructTeam::AbstructTeam;
    void teamGoal() override; // 重写父类目标函数
};
#endif