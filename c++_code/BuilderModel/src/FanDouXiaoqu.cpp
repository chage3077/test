#include "FanDouXiaoqu.h"

void FanDouXiaoqu::addHouses(string name)
{
    m_houses.push_back(name);
}

void FanDouXiaoqu::showHouses()
{
    for (const auto &item : m_houses) //基于范围的for循环
    {
        cout << item << " ";
    }
    cout << endl;
}
