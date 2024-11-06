#include "MyList.h"
#include "FrontIterator.h"
#include "BackIterator.h"
#include <vector>
int main()
{
    vector<string> data_list{"Jack", "Zeus", "Faker", "Jackeylove", "The shy", "Jiejie", "ON", "Zyko", "Viper"};
    MyList *ls = new MyList; // 需要new一个空间，不然ls为初始不能正常使用其成员遍历
    for (int i = 0; i < data_list.size(); i++)
    {
        // 从头部插入数据
        ls->insertFront(data_list.at(i));
    }
    // 正向遍历
    cout << "Is forward searching........" << endl;
    IteratorList *it = ls->getIterator(false); // 获取正向遍历的迭代器
    for (auto begin = it->first(); !it->isDone(); it->next())
    {
        cout << it->getCurrent()->m_data << " says:Hello!" << endl;
    }
    cout << "----------------------------------------" << endl;
    // 逆向遍历
    it = ls->getIterator(true);
    cout << "Is back searching..........." << endl;
    for (auto begin = it->first(); !it->isDone(); it->next())
    {
        cout << it->getCurrent()->m_data << " says:Hello!" << endl;
    }
    delete it;
    delete ls;
    return 0;
}