#include "NanYangXiaoqu.h"

void NanYangXiaoqu::assemble(string type_name, string house_name)
{
    m_houses.insert(make_pair(type_name, house_name));
}

void NanYangXiaoqu::showHouses()
{
    for (const auto &item : m_houses)
    {
        cout << item.first << ":" << item.second << endl;
    }
    cout << endl;
}
