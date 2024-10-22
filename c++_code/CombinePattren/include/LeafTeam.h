#ifndef LEAFTEAM_H
#define LEAFTEAM_H
#include "AbstructTeam.h"
class LeafTeam:public AbstructTeam
{
private:
    /* data */
public:
    using AbstructTeam::AbstructTeam; // 继承父类的构造函数
    // 重写父类虚函数
    void display() override;
    ~LeafTeam() override;
};

#endif