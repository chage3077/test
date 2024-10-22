#ifndef MANAGERTEAM_H
#define MANAGERTEAM_H
#include "AbstructTeam.h"
#include <list>
class ManagerTeam : public AbstructTeam
{
private:
    /* data */
    // 存储子节点
    list<AbstructTeam *> m_childs;

public:
    using AbstructTeam::AbstructTeam;
    void display() override;
    bool hasChild() override;
    list<AbstructTeam*> getChilds();
    void addChild(AbstructTeam *node) override;
    void deleteChild(AbstructTeam *node) override;
    ~ManagerTeam() override;
};
#endif