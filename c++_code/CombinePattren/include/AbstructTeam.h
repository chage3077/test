#ifndef ABSTRUCTTEAM_H
#define ABSTRUCTTEAM_H
#include <iostream>
#include <string>
using namespace std;
class AbstructTeam
{
private:
    /* data */
protected:
    string m_name;
    AbstructTeam *m_parent = nullptr; // 记录父节点地址
public:
    string getName();
    void setParentNode(AbstructTeam *node); // 设置父节点
    AbstructTeam *getParentNode();          // 获取父节点
    AbstructTeam(string name);
    // 虚函数
    virtual bool hasChild(); // 用于判断是否存在子节点 管理者节点重写即可
    // 不能设置成纯虚函数，因为叶子节点不需要重写这两个方法
    virtual void addChild(AbstructTeam *node) {};    // 用于添加子节点
    virtual void deleteChild(AbstructTeam *node) {}; // 用于删除子节点
    virtual void display() = 0;                      // 展示
    virtual ~AbstructTeam() {};
};
#endif