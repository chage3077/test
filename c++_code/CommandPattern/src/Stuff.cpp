#include "Stuff.h"

void Stuff::setOrder(int index, AbstructCommand *command)
{
    // 点菜
    cout << "Table number " << index << " : order " << command->name() << endl;
    // 判断该桌号是否新开桌（一个菜也没点）index不存在于map中
    if (m_cmdMap.find(index) == m_cmdMap.end())
    {
        list<AbstructCommand *> cmdLists = {command};
        m_cmdMap.insert(make_pair(index, cmdLists));
    }
    else
    {
        // 直接加菜即可
        m_cmdMap[index].push_back(command);
    }
}

void Stuff::deleteOrder(int index, AbstructCommand *command)
{
    if (m_cmdMap.find(index) != m_cmdMap.end())
    {
        if (!(m_cmdMap.find(index)->second.empty()))
        {
            // 该桌客人已点菜
            m_cmdMap[index].remove(command);
            cout << "The table:" << index << " remove " << command->name() << endl;
        }
    }
}

void Stuff::checkOut(int index)
{
    cout << "The table:" << index << " have ordered...." << endl;
    for (const auto &it : m_cmdMap[index])
    {
        cout << it->name();
        if (it != m_cmdMap[index].back()) // m_cmdMap[index]等价于List,list.back()的作用就是判断元素是不是最后一个
        {
            // 判断是不是点的最后一道菜
            cout << ","; // 分割作用
        }
    }
    cout << endl;
}

void Stuff::notify(int index)
{
    // 发送通知，厨师开始炒菜
    cout << "------Table " << index << "  is cooking-----------" << endl;
    for (const auto &it : m_cmdMap[index])
    {
        it->execute();
    }
}
