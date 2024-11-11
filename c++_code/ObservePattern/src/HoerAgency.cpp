#include "HoerAgency.h"
#include "Observer.h"
void HoerAgency::notify(string msg)
{
    cout << "Subscribing Hoerder Agency persons are :" << m_observer.size() << endl;
    for (const auto &it : m_observer)
    {
        // 通过观察者更新数据
        it->update(msg);
    }
}