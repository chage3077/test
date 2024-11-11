#include "MaierAgency.h"
#include "Observer.h"
void MaierAgency::notify(string msg)
{
    cout << "Subscribing Maiersenqin Agency persons are :" << m_observer.size() << endl;
    for (const auto &it : m_observer)
    {
        // 通过观察者更新数据
        it->update(msg);
    }
}