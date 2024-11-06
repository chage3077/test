#include "WorldGovt.h"
#include "Country.h"
void WorldGovt::declare(string msg, Country *country, string name)
{
    // 被宣称的国家是否在组织内
    if (m_countryMap.find(name) != m_countryMap.end())
    {
        string str = msg + " (from " + country->getName() + " ).";
        m_countryMap[name]->setMessage(str); // 被宣称的国家接收消息
    }
}