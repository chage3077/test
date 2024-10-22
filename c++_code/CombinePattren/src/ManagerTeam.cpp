#include "ManagerTeam.h"

void ManagerTeam::display()
{
    // 遍历所有的子节点，输出信息
    string info = "I am " + m_name + " and I have ";
    for (const auto &item : m_childs)
    {
        if (item == m_childs.back()) // 判断是不是最后一个子节点
        {
            info += item->getName();
        }
        else
        {
            info += item->getName() + ",";
        }
    }
    cout << info << endl;
}

bool ManagerTeam::hasChild()
{
    return true;
}

list<AbstructTeam *> ManagerTeam::getChilds()
{
    return m_childs;
}

void ManagerTeam::addChild(AbstructTeam *node)
{
    // 设置子节点的父亲
    node->setParentNode(this);
    // 放入容器中
    m_childs.push_back(node);
}

void ManagerTeam::deleteChild(AbstructTeam *node)
{
    // 将该子节点的父亲清空
    node->setParentNode(nullptr);
    // 移除容器
    m_childs.remove(node);
}

ManagerTeam::~ManagerTeam()
{
    cout<<m_name<<" is broken!"<<endl;
}
