#include "RevoluAmy.h"
#include "Country.h"
void RevoluAmy::declare(string msg, Country *country, string name)
{
    string str = msg + " (from " + country->getName() + " ).";
    // 发给每一个组织内的国家，除自己
    for (const auto it : m_countryMap)
    {
        if (it.second == country)
        {
            continue;
        }
        it.second->setMessage(str);
    }
}