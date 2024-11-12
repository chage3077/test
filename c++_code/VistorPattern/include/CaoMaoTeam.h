#ifndef CAOMAOTEAM_H
#define CAOMAOTEAM_H
#include<list>
#include<vector>
#include"AbstructMember.h"
class CaoMaoTeam
{
private:
    /* data */
    list<AbstructMember*>m_members;
    vector<AbstructAction*>m_actions; // 存储行为
public:
    CaoMaoTeam();
    ~CaoMaoTeam();
    // 添加草帽海贼团成员
    void addTeam(AbstructMember* member);
    // 删除
    void remove(AbstructMember* member);
    // 遍历函数
    void display();

};

#endif