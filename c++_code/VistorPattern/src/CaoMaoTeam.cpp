#include "CaoMaoTeam.h"
#include "AngerAction.h"
#include "HorrorAction.h"
CaoMaoTeam::CaoMaoTeam()
{
    m_actions.push_back(new AngerAction);
    m_actions.push_back(new HorrorAction);
}

CaoMaoTeam::~CaoMaoTeam()
{
    for (const auto &item : m_actions)
    {
        delete item;
    }
    for (const auto &item : m_members)
    {
        delete item;
    }
}

void CaoMaoTeam::addTeam(AbstructMember *member)
{
    m_members.push_back(member);
}

void CaoMaoTeam::remove(AbstructMember *member)
{
    m_members.remove(member);
}

void CaoMaoTeam::display()
{
    for (const auto &item : m_members)
    {
        int index = rand() % 2; // 随机获取行为
        item->accept(m_actions.at(index));
    }
}
