#include "AbstructTeam.h"
string AbstructTeam::getName()
{
    return m_name;
}

void AbstructTeam::addPerson(Person *person)
{
    // 将人添加到map容器中
    m_teamMap.insert(make_pair(person->name, person));
}

void AbstructTeam::showTeam()
{
    // 遍历容器展示
    cout << "Our team name is:" << m_name << endl;
    cout << "These are our persons." << endl;
    for (const auto &p : m_teamMap)
    {
        cout << "name:" << p.second->name << " "
             << "age:" << p.second->age << " "
             << "ability:" << p.second->ability << " "
             << "job:" << p.second->job << endl;
    }
}

AbstructTeam::~AbstructTeam()
{
    // 将存储的person清除
    for (const auto &p : m_teamMap)
    {
        delete p.second;
    }
}
